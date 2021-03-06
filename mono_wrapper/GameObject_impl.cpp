#include "stdafx.h"
#include "GameObject_impl.h"
#include "mono_wrapper/String.h"
#include "mono_wrapper/Transform.h"

namespace mono_wrapper
{

GameObject_impl::GameObject_impl(functions_cptr f, MonoObject *p)
    : Object_impl(f, p)
{}
                                         
String_ptr GameObject_impl::get_name() 
{                                            
    MonoMethod *m = base().get_getter("name");
    return wrap_String(base().get_f(), base().invoke_method(m, nullptr));
}

Transform_ptr GameObject_impl::get_transform() 
{
    MonoMethod *m = base().get_getter("transform");
    return wrap_Transform(base().get_f(), base().invoke_method(m, nullptr));
}

int32_t GameObject_impl::GetInstanceID() 
{
    MonoMethod *m = base().get_method("GetInstanceID", 0);

    return base().unbox<int32_t>(base().invoke_method(m, nullptr));
}

GameObject_ptr wrap_GameObject(functions_cptr f, MonoObject *p)
{
    return make_shared<GameObject_impl>(f, p);
}


} // namespace mono_wrapper