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

MonoObject* executor_impl::mono_runtime_invoke(MonoMethod* method, void* obj, void** params, MonoObject** exc) 
{
    char const *name = get_f().mono_method_get_name(method);
    MonoClass *klass = get_f().mono_method_get_class(method);

    if (obj)
    {
        auto obj_cast = reinterpret_cast<MonoObject *>(obj);
        if (auto obj_class = get_f().mono_object_get_class(obj_cast))
            klass = obj_class;
        else
        {
            int aaa = 5;
        }
    }

    char const *class_name = get_f().mono_class_get_name(klass);    
    
    update_stats(class_name, name);
    return get_f().mono_runtime_invoke(method, obj, params, exc);
}


void executor_impl::print_stats()
{
    monitor::update_stats(stats_);
}

void executor_impl::update_stats(char const *class_name, char const *name)
{
    boost::mutex::scoped_lock l(stats_mutex_);
   
    stats_key_t key(class_name, name);

    auto it = stats_.find(key);
    if (it == stats_.end())    
        it = stats_.emplace(key, 0).first;

    ++it->second;

    time_point_t now = std::chrono::system_clock::now();
    if (!last_stats_update_ || std::chrono::duration_cast<std::chrono::seconds>(now - *last_stats_update_).count() > 10)
    {
        print_stats();
        stats_.clear();
        last_stats_update_ = now;
    }

}


