#pragma once

#include "executor_base.h"
#include "stats.h"
#include "executor_control.h"

#include "mono_wrapper/mono_wrapper_fwd.h"

struct executor_impl
    : executor_base
    , executor_control
{
    executor_impl();
    ~executor_impl();
    
    MonoObject* mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc) override;

private:
    void go(task_t const &callback) override;
    
private:
    void go_impl(task_t const &callback);

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