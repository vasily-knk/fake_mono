#pragma once

#include "stdafx.h"
#include "mono_wrapper/Array.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct Array_impl
    : virtual Object_impl
    , virtual Array
{
    Array_impl(functions_cptr f, MonoObject *p);
    
    // Array
public:
    int32_t get_Length() override final;
    Object_ptr Get(int32_t index) override final;
};


}

