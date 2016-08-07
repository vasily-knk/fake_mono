#include "stdafx.h"
#include "executor_impl.h"
#include "log.h"
#include "stl_helpers.h"
#include "monitor.h"


executor_ptr create_executor()
{
    return make_shared<executor_impl>();
}

executor_impl::executor_impl()
    : monitor_thread_(monitor::run)
{
}

executor_impl::~executor_impl()
{
    monitor_thread_.join();
}

MonoObject* executor_impl::mono_runtime_invoke(MonoMethod* method, void* p_obj, void** params, MonoObject** exc) 
{
    char const *method_name = get_f().mono_method_get_name(method);
    if (!strcmp(method_name, "FixedUpdate"))
    {
        MonoObject *obj = static_cast<MonoObject *>(p_obj);
        MonoClass *klass = get_f().mono_object_get_class(obj);
        char const *class_name = get_f().mono_class_get_name(klass);

            process_fixed_update();
    }
    
    return executor_base::mono_runtime_invoke(method, p_obj, params, exc);
}


MonoAssembly* executor_impl::mono_assembly_open(const char* filename, int* status) 
{
    auto assembly = executor_base::mono_assembly_open(filename, status);
    add_assembly(assembly, filename);
    return assembly;
}

MonoAssembly* executor_impl::mono_assembly_load_from(MonoImage* image, const char* fname, int* status) 
{
    auto assembly = executor_base::mono_assembly_load_from(image, fname, status);
    add_assembly(assembly, fname);
    return assembly;
}

MonoAssembly* executor_impl::mono_assembly_load_from_full(MonoImage* image, const char* fname, int* status, gboolean refonly) 
{
    auto assembly = executor_base::mono_assembly_load_from_full(image, fname, status, refonly);
    add_assembly(assembly, fname);
    return assembly;
}

void executor_impl::mono_assembly_close(MonoAssembly* assembly) 
{
    return executor_base::mono_assembly_close(assembly);
}

void executor_impl::add_assembly(MonoAssembly *assembly, char const *fname)
{
    std::stringstream ss;
    
    assembly_desc_t desc;
    desc.name = fname;
    desc.image = get_f().mono_assembly_get_image(assembly);

    {
        auto names = get_assembly_names();
        for (string const &name : names)
            ss << name << "\n";

        monitor::print(ss.str());
    }
    
    {
        boost::mutex::scoped_lock lock(mutex_);

        assemblies_.emplace(assembly, desc);
        
        if (check_unity_engine_assembly(fname))
            init_unity_engine_assembly(assembly);

    }

}

void executor_impl::init_unity_engine_assembly(MonoAssembly *assembly)
{
    unity_engine_assembly_ = assembly;


}


bool executor_impl::check_unity_engine_assembly(char const *fname)
{
    fs::path p(fname);
    fs::path desired("UnityEngine.dll");
    return p.filename() == desired;
}

namespace get_assembly_names_detail
{
    struct context_t
    {
        context_t(functions_t const &functions)
            : functions(functions)
        {}

        functions_t const &functions;
        vector<string> dst;
    };
    
    void visit_assembly(void *p_assembly, void *p_userdata)
    {
        MonoAssembly *assembly = static_cast<MonoAssembly*>(p_assembly);
        context_t *context = static_cast<context_t*>(p_userdata);

        MonoImage *image = context->functions.mono_assembly_get_image(assembly);
        context->dst.push_back(context->functions.mono_image_get_name(image));
        
    }
}

vector<string> executor_impl::get_assembly_names()
{
    using namespace get_assembly_names_detail;
    
    context_t context(get_f());

    get_f().mono_assembly_foreach(static_cast<GFunc>(&visit_assembly), &context);

    return std::move(context.dst);
}


namespace find_image_by_name_detail
{
    struct context_t
    {
        context_t(functions_t const &functions, char const *name)
            : functions(functions)
            , name(name)
        {}

        functions_t const &functions;
        char const *name;
        MonoImage *result = nullptr;
    };

    void visit_assembly(void *p_assembly, void *p_userdata)
    {
        context_t *context = static_cast<context_t*>(p_userdata);
        if (context->result)
            return;
        
        MonoAssembly *assembly = static_cast<MonoAssembly*>(p_assembly);
        MonoImage *image = context->functions.mono_assembly_get_image(assembly);
        char const *name = context->functions.mono_image_get_name(image);

        if (!strcmp(name, context->name))
            context->result = image;
    }
}

MonoImage *executor_impl::find_image_by_name(char const *name)
{
    using namespace find_image_by_name_detail;
    
    context_t context(get_f(), name);
    get_f().mono_assembly_foreach(static_cast<GFunc>(&visit_assembly), &context);
    return context.result;
}


void executor_impl::process_fixed_update()
{
    auto get_class_name = [this](MonoObject *obj) -> char const *
    {
        if (!obj)
            return nullptr;
        
        MonoClass *klass = get_f().mono_object_get_class(obj);
        return get_f().mono_class_get_name(klass);
    };


    auto get_property = [this](MonoObject *obj, char const *name) -> MonoObject *
    {
        MonoClass *klass = get_f().mono_object_get_class(obj);
        MonoProperty *prop = get_f().mono_class_get_property_from_name(klass, name);
        MonoMethod *getter = get_f().mono_property_get_get_method(prop);

        return get_f().mono_runtime_invoke(getter, obj, nullptr, nullptr);
    };

    MonoDomain *domain = get_f().mono_domain_get();
    
    MonoImage *unity_engine = find_image_by_name("UnityEngine");
    MonoClass *gameobject_class = get_f().mono_class_from_name(unity_engine, "UnityEngine", "GameObject");
    MonoType *gameobject_type = get_f().mono_class_get_type(gameobject_class);
    MonoObject *gameobject_type_object = get_f().mono_type_get_object(domain, gameobject_type);
    
    MonoClass *unity_object_class = get_f().mono_class_from_name(unity_engine, "UnityEngine", "Object");
    MonoMethod *find_objects_of_type = get_f().mono_class_get_method_from_name(unity_object_class, "FindObjectsOfType", 1);
    char const *full_name = get_f().mono_method_full_name(find_objects_of_type, true);

    void *args[] = {gameobject_type_object};

    MonoObject *result = get_f().mono_runtime_invoke(find_objects_of_type, nullptr, args, nullptr);
    MonoClass *result_class = get_f().mono_object_get_class(result);

    char const *result_class_name = get_class_name(result);

    MonoObject *len = get_property(result, "Length");
    char const *len_class_name = get_class_name(len);

    auto len_val = static_cast<uint32_t const *>(get_f().mono_object_unbox(len));

}

MonoObject *executor_impl::get_type_by_name(char const *name)
{
    MonoImage *core = find_image_by_name("mscorlib");
    MonoClass *type_class = get_f().mono_class_from_name(core, "System", "Type");
    MonoMethod *get_type_method = get_f().mono_class_get_method_from_name(type_class, "GetType", 1);

    MonoString *name_string = get_f().mono_string_new_wrapper(name);
    void* args[1] = {name_string};

    MonoObject *ex = nullptr;
    MonoObject *result = get_f().mono_runtime_invoke(get_type_method, nullptr, args, &ex);
    return result;
}
