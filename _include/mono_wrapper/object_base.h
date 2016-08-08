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
        f_->mono_gchandle_free(handle_);
    }

    class_desc_t get_class()
    {
        MonoClass *p = f_->mono_object_get_class(get_object());
        return class_desc_t(f_, p);
    }

public:
    MonoObject *get_object() const
    {
        return f_->mono_gchandle_get_target(handle_);
    }

    MonoMethod *get_method(char const *name, int params_count) const
    {
        MonoClass *klass = f_->mono_object_get_class(get_object());
        return f_->mono_class_get_method_from_name(klass, name, params_count);
    }

    MonoObject *invoke_method(MonoMethod *m, void *args[]) const
    {
        return f_->mono_runtime_invoke(m, get_object(), args, nullptr);
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