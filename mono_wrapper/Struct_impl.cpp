#include "stdafx.h"
#include "Struct_impl.h"

namespace mono_wrapper
{

Struct_impl::Struct_impl(functions_cptr f, MonoObject *p)
    : Object_impl(f, p)
{}

void const* Struct_impl::raw_ptr() const
{
    auto base_ptr = reinterpret_cast<uint32_t const *>(base().get_object());
    return base_ptr + 2;
}

Struct_ptr wrap_Struct(functions_cptr f, MonoObject *p)
{
    return make_shared<Struct_impl>(f, p);
}



} // namespace mono_wrapper