#pragma once

#include "executor_base.h"
#include "stats.h"
#include "executor_control.h"

#include "mono_wrapper/mono_wrapper_fwd.h"

struct executor_impl
    : executor_base
    , std::enable_shared_from_this<executor_impl>
{
    executor_impl();
    ~executor_impl();
    
    // executor_base
public:
    MonoDomain* mono_jit_init(const char* file) override;
    MonoDomain* mono_jit_init_version(const char* file, const char* runtime_version) override;
    MonoObject* mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc) override;
    void mono_set_dirs(const char* assembly_dir, const char* config_dir) override;
    void mono_add_internal_call(const char* name, gconstpointer method) override;
    MonoThread* mono_thread_attach(MonoDomain* domain) override;

    // own
private:
    void init(MonoDomain *domain);
    void init_watcher_impl();
	void init_debugger();

private:
    struct watcher_data_t;
    watcher_data_t const &get_watcher_data() const;
    void init_watcher_data() const;

private:
    void create_watcher();
    static void unregister_watcher(MonoObject *game_object);

private:
    vector<string> get_assembly_names();

    MonoImage *executor_impl::find_image_by_name(char const *name);
    MonoObject *get_type_by_name(char const *name);

    static void internal_print(MonoString *str);

private:
    static void create_gameobject(MonoObject *go, MonoObject *name);
    static MonoObject *clone_single(MonoObject *data);
    static MonoObject *instantiate_single(MonoObject *data, MonoStruct_out pos, MonoStruct_out rot);

    static void register_gameobject(MonoObject *go);

private:
    static gconstpointer real_create_gameobject;
    static gconstpointer real_clone_single;
    static gconstpointer real_instantiate_single;

private:
    fs::path assembly_dir_;
    mutable boost::mutex assembly_dir_mutex_;

private:
    shared_ptr<boost::thread::id> main_thread_id_;
    std::atomic<bool> pending_watcher_creation_ = true;

    static std::map<MonoObject *, std::weak_ptr<executor_impl>> watchers_to_executors_;

    struct watcher_data_t
    {
        MonoAssembly *assembly = nullptr;
        MonoImage *image = nullptr;
        MonoMethod *create_method = nullptr;
        shared_ptr<mono_wrapper::functions_t> f;
    };

    mutable optional<watcher_data_t> watcher_data_;
};