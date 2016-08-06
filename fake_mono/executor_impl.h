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
    void print_stats();
    void update_stats(char const *class_name, char const *name);

private:
    void update_uber_pool_group(MonoObject *obj);

private:
    stats_t stats_;
    boost::mutex stats_mutex_;

    typedef std::chrono::time_point<std::chrono::system_clock> time_point_t;
    optional<time_point_t> last_stats_update_;

private:
    boost::thread monitor_thread_;
};