#pragma once

#include "executor_base.h"
#include "stats.h"

struct executor_impl
    : executor_base
{
    executor_impl();
    ~executor_impl();
    
    MonoObject* mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc) override;

private:
    MonoAssembly* mono_assembly_open(const char* filename, int* status) override;
    MonoAssembly* mono_assembly_load_from(MonoImage* image, const char* fname, int* status) override;
    MonoAssembly* mono_assembly_load_from_full(MonoImage* image, const char* fname, int* status, gboolean refonly) override;
    void mono_assembly_close(MonoAssembly* assembly) override;

private:
    void process_fixed_update();
    void post(std::function<void()> const &task);

private:
    void add_assembly(MonoAssembly *assembly, char const *fname);

    bool check_unity_engine_assembly(char const *fname);
    void init_unity_engine_assembly(MonoAssembly *assembly);

    vector<string> get_assembly_names();

    MonoImage *executor_impl::find_image_by_name(char const *name);
    MonoObject *get_type_by_name(char const *name);

private:
    struct assembly_desc_t
    {
        string name;
        MonoImage *image;
    };

    typedef std::map<MonoAssembly *, assembly_desc_t> assemblies_t;

    assemblies_t assemblies_;
    MonoAssembly *unity_engine_assembly_ = nullptr;
    boost::mutex mutex_;

private:
    boost::thread monitor_thread_;

private:
    vector<std::function<void()>> tasks_;
    boost::mutex tasks_mutex_;
};