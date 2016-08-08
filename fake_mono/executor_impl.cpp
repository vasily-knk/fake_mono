#include "stdafx.h"
#include "executor_impl.h"
#include "log.h"
#include "common/stl_helpers.h"
#include "monitor.h"

#include "mono_wrapper/Array.h"
#include "mono_wrapper/String.h"
#include "mono_wrapper/GameObject.h"
#include "mono_wrapper/Transform.h"


executor_ptr create_executor()
{
    return make_shared<executor_impl>();
}

executor_impl::executor_impl()
{
    auto worker = boost::bind(&monitor::run, this);
    monitor_thread_ = boost::thread(worker);
}

executor_impl::~executor_impl()
{
    monitor_thread_.join();
}

MonoObject* executor_impl::mono_runtime_invoke(MonoMethod* method, void* p_obj, void** params, MonoObject** exc) 
{
    char const *method_name = get_f().mono_method_get_name(method);
    char const *method_full_name = get_f().mono_method_full_name(method, true);
    if (!strcmp(method_name, "FixedUpdate"))
    {
        MonoObject *obj = static_cast<MonoObject *>(p_obj);
        MonoClass *klass = get_f().mono_object_get_class(obj);
        char const *class_name = get_f().mono_class_get_name(klass);

        process_fixed_update();
    }
    
    return executor_base::mono_runtime_invoke(method, p_obj, params, exc);
}


namespace get_assembly_names_detail
{
    struct context_t
    {
        context_t(mono_wrapper::functions_t const &functions)
            : functions(functions)
        {}

        mono_wrapper::functions_t const &functions;
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
        context_t(mono_wrapper::functions_t const &functions, char const *name)
            : functions(functions)
            , name(name)
        {}

        mono_wrapper::functions_t const &functions;
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
     boost::mutex::scoped_lock lock(tasks_mutex_);
     for (auto const &task : tasks_)
         task();

     tasks_.clear();
 }

void executor_impl::post(std::function<void()> const &task)
{
     boost::mutex::scoped_lock lock(tasks_mutex_);
     tasks_.push_back(task);
}


// void executor_impl::process_fixed_update()
// {

// 
// }

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

void executor_impl::go_impl(task_t const &callback) 
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

    auto fptr = make_shared<mono_wrapper::functions_t>(get_f());

    auto arr = mono_wrapper::wrap_Array(fptr, result);

    auto len = arr->get_Length();

    std::stringstream ss;

    ss << "Scene objects:\n\n";
    for (int32_t i = 0; i < len; ++i)
    {
        auto obj = arr->Get(i);
        auto game_object = mono_wrapper::wrap_GameObject(fptr, obj->get_mono_object());

        auto transform = game_object->get_transform();
        auto position = transform->get_position();
        ss << "   " << game_object->get_name()->to_utf8() << "\n";

    }

    monitor::print(ss.str());
    
//     {
//         MonoClass *klass = fptr->mono_object_get_class(result);
//         gpointer iter = nullptr;
//         
// 
//         while (MonoMethod *m = fptr->mono_class_get_methods(klass, &iter))
//         {
//             char const * mn = fptr->mono_method_full_name(m, true);
//             ss << mn << "\n";
//         }
// 
//     }
    
    monitor::post(callback);
}

void executor_impl::go(task_t const &callback) 
{
    auto task = boost::bind(&executor_impl::go_impl, this, callback);
    
    post(task);
}