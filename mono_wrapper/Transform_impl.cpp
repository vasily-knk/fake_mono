#include "stdafx.h"
#include "Transform_impl.h"
#include "mono_wrapper/String.h"
#include "mono_wrapper/Transform.h"
#include "mono_wrapper/GameObject.h"

namespace mono_wrapper
{

Transform_impl::Transform_impl(functions_cptr f, MonoObject *p)
    : super_(f, p)
{}

Object_ptr Transform_impl::get_position() 
{
    MonoMethod *m = base().get_getter("position");
    return wrap_Transform(base().get_f(), base().invoke_method(m, nullptr));
}

GameObject_ptr Transform_impl::get_gameObject()
{
    MonoMethod *m = base().get_getter("gameObject");
    return wrap_GameObject(base().get_f(), base().invoke_method(m, nullptr));
}

String_ptr  Transform_impl::ToString       ()               { return super_.ToString()       ; }
bool        Transform_impl::Equals         (Object_ptr obj) { return super_.Equals(obj)      ; }
MonoObject *Transform_impl::get_mono_object()         const { return super_.get_mono_object(); }
char const *Transform_impl::get_class_name ()         const { return super_.get_class_name();  }

object_base const &Transform_impl::base() const { return super_.base(); }


Transform_ptr wrap_Transform(functions_cptr f, MonoObject *p)
{
    return make_shared<Transform_impl>(f, p);
}


} // namespace mono_wrapper