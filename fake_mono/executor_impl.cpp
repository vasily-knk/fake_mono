#include "stdafx.h"
#include "executor_impl.h"
#include "log.h"
#include "common/stl_helpers.h"
#include "monitor.h"

#include "mono_wrapper/Array.h"
#include "mono_wrapper/String.h"
#include "mono_wrapper/GameObject.h"
#include "mono_wrapper/Transform.h"


std::map<MonoObject*, std::weak_ptr<executor_impl>> executor_impl::watchers_to_executors_;


executor_ptr create_executor()
{
    return make_shared<executor_impl>();
}

executor_impl::executor_impl()
{
    //monitor_thread_ = boost::thread(boost::bind(&monitor::run, this));
}

void executor_impl::init(MonoDomain *domain)
{
    main_thread_id_ = std::make_shared<boost::thread::id>(boost::this_thread::get_id());
}

MonoThread* executor_impl::mono_thread_attach(MonoDomain* domain) 
{
    return executor_base::mono_thread_attach(domain);
}

MonoDomain* executor_impl::mono_jit_init(const char* file)
{
    auto domain = executor_base::mono_jit_init(file);
    init(domain);
    return domain;
}

MonoDomain* executor_impl::mono_jit_init_version(const char* file, const char* runtime_version)
{
    auto domain = executor_base::mono_jit_init_version(file, runtime_version);
    init(domain);
    return domain;
}

void executor_impl::mono_add_internal_call(const char* name, gconstpointer method)
{
    log_stream() << "Internal method: " << name << std::endl;
    executor_base::mono_add_internal_call(name, method);
}

executor_impl::~executor_impl()
{
}

MonoObject* executor_impl::mono_runtime_invoke(MonoMethod* method, void* p_obj, void** params, MonoObject** exc) 
{
    if (pending_watcher_creation_.load())
    {
        auto thread_id = boost::this_thread::get_id();
        if (thread_id == *main_thread_id_)
        {
            static std::array<char const *, 3> method_names = 
            {
                "FixedUpdate",
                "Update",
                "Start",
            };
            
            char const *method_name = get_f().mono_method_get_name(method);
            auto it = boost::find_if(method_names, [method_name](char const *n)
            {
                return !strcmp(n, method_name);
            });

            if (it != method_names.end())
            {
                bool expected = true;
                if (pending_watcher_creation_.compare_exchange_strong(expected, false))
                    create_watcher();
            }
        }
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


void executor_impl::mono_set_dirs(const char* assembly_dir, const char* config_dir) 
{
    executor_base::mono_set_dirs(assembly_dir, config_dir);
    
    {
        boost::mutex::scoped_lock l(assembly_dir_mutex_);
        assembly_dir_ = assembly_dir;
    }
}

void executor_impl::create_watcher()
{
    Verify(boost::this_thread::get_id() == *main_thread_id_);

    watcher_data_t const &watcher_data = get_watcher_data();
    MonoObject *game_object = get_f().mono_runtime_invoke(watcher_data.create_method, nullptr, nullptr, nullptr);
    Verify(game_object);

    Verify(watchers_to_executors_.count(game_object) == 0);
    
    std::weak_ptr<executor_impl> weak_this = shared_from_this();
    watchers_to_executors_.emplace(game_object, weak_this);
}

void executor_impl::unregister_watcher(MonoObject *game_object)
{
    auto it = watchers_to_executors_.find(game_object);
    Verify(it != watchers_to_executors_.end());

    auto self = it->second.lock();
    watchers_to_executors_.erase(it);

    if (self)
        self->pending_watcher_creation_.store(true);
}

auto executor_impl::get_watcher_data() const -> watcher_data_t const &
{
    Verify(boost::this_thread::get_id() == *main_thread_id_);
    
    if (!watcher_data_)
        init_watcher_data();

    return *watcher_data_;
}

void executor_impl::init_watcher_data() const 
{
    string lib_name = "ClassLibrary1";
    
    Verify(boost::this_thread::get_id() == *main_thread_id_);

    auto fptr = make_shared<mono_wrapper::functions_t>(get_f());
    fs::path assembly_path;
    {
        boost::mutex::scoped_lock l(assembly_dir_mutex_);
        assembly_path = assembly_dir_ / fs::path(lib_name + ".dll");
    }

    int status = 0;
    MonoAssembly *assembly = fptr->mono_assembly_open(assembly_path.string().c_str(), &status);
    MonoImage *image = fptr->mono_assembly_get_image(assembly);
    char const *name = fptr->mono_image_get_name(image);

    fptr->mono_add_internal_call((lib_name + ".Class1::Print").c_str(), &internal_print);
    fptr->mono_add_internal_call((lib_name + ".MyWatcher::OnObjectDestroying").c_str(), &unregister_watcher);

    MonoClass *klass = fptr->mono_class_from_name(image, lib_name.c_str(), "MyWatcher");
    MonoMethod *create_method = fptr->mono_class_get_method_from_name(klass, "CreateObject", 0);

    watcher_data_ = watcher_data_t();
    watcher_data_->assembly = assembly;
    watcher_data_->image = image;
    watcher_data_->create_method = create_method;
}

void executor_impl::internal_print(MonoString *str)
{
    char const *cstr = get_f().mono_string_to_utf8(str);
    OutputDebugStringA(cstr);
    log_stream() << cstr << std::flush;
}
