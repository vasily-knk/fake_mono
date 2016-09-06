#pragma once

#include "stdafx.h"
#include "mono_wrapper/Struct.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct Struct_impl
    : virtual Object_impl
    , virtual Struct
{
    Struct_impl(functions_cptr f, MonoObject *p);
    
public:
    void const *raw_ptr() const override;
};


}

