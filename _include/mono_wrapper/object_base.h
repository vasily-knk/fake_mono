#pragma once

#include "functions.h"
#include "class_desc.h"

namespace mono_wrapper
{

struct object_base
{
    object_base(functions_cptr f, MonoObject *p)
        : f_(f)
        , handle_(f->mono_gchandle_new(p, false))
    {}

    ~object_base()
    {
        //f_->mono_gchandle_free(handle_);
    }


public:
    MonoObject *get_object() const
    {
        return f_->mono_gchandle_get_target(handle_);
    }
    
    MonoClass *get_class() const
    {
        return f_->mono_object_get_class(get_object());
    }

    MonoMethod *get_method(char const *name, int params_count) const
    {
        for (MonoClass *klass = get_class(); klass; klass = f_->mono_class_get_parent(klass))
        {
            if (MonoMethod *method = f_->mono_class_get_method_from_name(klass, name, params_count))
                return method;
        }

        return nullptr;
    }

    MonoMethod *get_getter(char const *name) const
    {
        for (MonoClass *klass = get_class(); klass; klass = f_->mono_class_get_parent(klass))
        {
            if (MonoProperty *prop = f_->mono_class_get_property_from_name(klass, name))
                return f_->mono_property_get_get_method(prop);
        }

        return nullptr;
    }

    MonoObject *invoke_method(MonoMethod *m, void *args[]) const
    {
        return f_->mono_runtime_invoke(m, get_object(), args, nullptr);
    }
    
    MonoObject *invoke_method_ex(MonoMethod *m, void *args[], MonoObject** exc) const
    {
        return f_->mono_runtime_invoke(m, get_object(), args, exc);
    }

    template<typename T>
    T unbox(MonoObject *obj) const
    {
        return *static_cast<T const *>(f_->mono_object_unbox(obj));
    }

    functions_cptr get_f() const
    {
        return f_;
    }

private:
    functions_cptr f_;
    guint32 handle_ = 0;
};

typedef shared_ptr<object_base> object_base_ptr;

} // namespace mono_wrapper