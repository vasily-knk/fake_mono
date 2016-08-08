#include "stdafx.h"
#include "mono_wrapper/Object.h"
#include "mono_wrapper/String.h"
#include "mono_wrapper/object_base.h"

#include "Object_impl.h"

namespace mono_wrapper
{

Object_impl::Object_impl(functions_cptr f, MonoObject *p)
    : base_(f, p)
{
}
    
String_ptr Object_impl::ToString() 
{
    static MonoMethod *m = base().get_method("ToString", 0);
    return wrap_String(base().get_f(), base().invoke_method(m, nullptr));
}
    
bool Object_impl::Equals(Object_ptr obj) 
{
    static MonoMethod *m = base().get_method("Equals", 1);

    void *args[] = { obj->get_mono_object() };
    return base().unbox<bool>(base().invoke_method(m, args));
}
    
MonoObject *Object_impl::get_mono_object() const 
{
    return base().get_object();
}

object_base const &Object_impl::base() const
{
    return base_;
}

Object_ptr wrap_Object(functions_cptr f, MonoObject *p)
{
    return make_shared<Object_impl>(f, p);
}

}