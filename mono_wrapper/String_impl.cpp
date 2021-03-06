#include "stdafx.h"
#include "String_impl.h"

namespace mono_wrapper
{

String_impl::String_impl(functions_cptr f, MonoObject *p)
    : Object_impl(f, p)
{}

int32_t String_impl::get_Length() 
{
    MonoMethod *m = base().get_getter("Length");
    return base().unbox<bool>(base().invoke_method(m, nullptr));
}

String_ptr String_impl::ToUpper() 
{
    MonoMethod *m = base().get_method("ToUpper", 0);
    return wrap_String(base().get_f(), base().invoke_method(m, nullptr));
}

char const *String_impl::to_utf8() const 
{
    return base().get_f()->mono_string_to_utf8(get_mono_object());
}

String_ptr wrap_String(functions_cptr f, MonoObject *p)
{
    return make_shared<String_impl>(f, p);
}

String_ptr new_String(functions_cptr f, char const *str)
{
    MonoString *p = f->mono_string_new_wrapper(str);
    return make_shared<String_impl>(f, p);
}


} // namespace mono_wrapper