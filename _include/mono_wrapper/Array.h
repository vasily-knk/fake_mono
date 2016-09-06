#pragma once

#include "mono_wrapper/Object.h"

namespace mono_wrapper
{

struct Array
    : virtual Object
{
    virtual int32_t get_Length() = 0;
    virtual Object_ptr Get(int32_t index) = 0;
};

Array_ptr wrap_Array(functions_cptr f, MonoObject *p);

} // namespace mono_wrapper