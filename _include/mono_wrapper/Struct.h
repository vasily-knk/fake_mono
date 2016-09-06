#pragma once

#include "mono_wrapper/Object.h"

namespace mono_wrapper
{

struct Struct
    : virtual Object
{
    virtual void const *raw_ptr() const = 0;

    template<typename T>
    T const &get_value() const
    {
        return *reinterpret_cast<T const *>(raw_ptr());
    }
};

Struct_ptr wrap_Struct(functions_cptr f, MonoObject *p);

} // namespace mono_wrapper