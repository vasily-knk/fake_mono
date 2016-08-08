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
    void process_fixed_update();
    void post(std::function<void()> const &task);

private:

    vector<string> get_assembly_names();

    MonoImage *executor_impl::find_image_by_name(char const *name);
    MonoObject *get_type_by_name(char const *name);

private:
    boost::thread monitor_thread_;

private:
    vector<std::function<void()>> tasks_;
    boost::mutex tasks_mutex_;
};