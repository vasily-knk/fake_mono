#include "stdafx.h"
#include "Struct_impl.h"

namespace mono_wrapper
{

Struct_impl::Struct_impl(functions_cptr f, MonoObject *p)
    : super_(f, p)
{}

void const* Struct_impl::raw_ptr() const
{
    auto base_ptr = reinterpret_cast<uint32_t const *>(base().get_object());
    return base_ptr + 2;
}

String_ptr  Struct_impl::ToString       ()               { return super_.ToString()       ; }
bool        Struct_impl::Equals         (Object_ptr obj) { return super_.Equals(obj)      ; }
MonoObject *Struct_impl::get_mono_object()         const { return super_.get_mono_object(); }
char const *Struct_impl::get_class_name ()         const { return super_.get_class_name();  }

object_base const &Struct_impl::base() const { return super_.base(); }


Struct_ptr wrap_Struct(functions_cptr f, MonoObject *p)
{
    return make_shared<Struct_impl>(f, p);
}



} // namespace mono_wrapper