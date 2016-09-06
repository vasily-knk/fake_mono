#include "stdafx.h"
#include "Transform_impl.h"
#include "mono_wrapper/Transform.h"
#include "mono_wrapper/GameObject.h"
#include "mono_wrapper/Vector3.h"
#include "mono_wrapper/Struct.h"

namespace mono_wrapper
{

Transform_impl::Transform_impl(functions_cptr f, MonoObject *p)
    : Object_impl(f, p)
{}

Struct_ptr Transform_impl::get_position() 
{
    MonoMethod *m = base().get_getter("position");
    auto result = base().invoke_method(m, nullptr);
    return wrap_Struct(base().get_f(), result); 
}

GameObject_ptr Transform_impl::get_gameObject()
{
    MonoMethod *m = base().get_getter("gameObject");
    return wrap_GameObject(base().get_f(), base().invoke_method(m, nullptr));
}

Transform_ptr wrap_Transform(functions_cptr f, MonoObject *p)
{
    return make_shared<Transform_impl>(f, p);
}


} // namespace mono_wrapper