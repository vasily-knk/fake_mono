#include "stdafx.h"
#include "Array_impl.h"

namespace mono_wrapper
{

Array_impl::Array_impl(functions_cptr f, MonoObject *p)
    : super_(f, p)
{}

int32_t Array_impl::get_Length() 
{
    MonoMethod *m = base().get_getter("Length");
    return base().unbox<bool>(base().invoke_method(m, nullptr));
}

Object_ptr Array_impl::Get(int32_t index) 
{
    MonoMethod *m = base().get_method("Get", 1);

    void *args[] = { &index };
    return wrap_Object(base().get_f(), base().invoke_method(m, args));
}

String_ptr  Array_impl::ToString       ()               { return super_.ToString()       ; }
bool        Array_impl::Equals         (Object_ptr obj) { return super_.Equals(obj)      ; }
MonoObject *Array_impl::get_mono_object()        const  { return super_.get_mono_object(); }
char const *Array_impl::get_class_name ()         const { return super_.get_class_name();  }

object_base const &Array_impl::base() const { return super_.base(); }


Array_ptr wrap_Array(functions_cptr f, MonoObject *p)
{
    return make_shared<Array_impl>(f, p);
}


} // namespace mono_wrapper