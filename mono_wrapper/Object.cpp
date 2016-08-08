#include "stdafx.h"
#include "mono_wrapper/Object.h"
#include "mono_wrapper/object_base.h"

namespace mono_wrapper
{

struct Object_impl
    : object_base
    , Object
{
    Object_ptr ToString() override
    {
        static MonoMethod *m = get_method("ToString", 0);
        return wrap_Object(get_f(), invoke_method(m, nullptr));
    }
    
    bool Equals(Object_ptr obj) override
    {
        static MonoMethod *m = get_method("Equals", 1);

        void *args[] = {obj->get_mono_object()};
        MonoObject *ret = invoke_method(m, args);
        return *static_cast<bool const*>(get_f()->mono_object_unbox(ret));
    }
    
    MonoObject *get_mono_object() const override
    {
        return get_object();
    }
};


}