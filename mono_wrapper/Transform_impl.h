#pragma once

#include "stdafx.h"
#include "mono_wrapper/Transform.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct Transform_impl
    : virtual Object_impl
    , virtual Transform
{
    Transform_impl(functions_cptr f, MonoObject *p);
    
    // Transform
public:
    Struct_ptr get_position() override;
    GameObject_ptr get_gameObject() override;
};


}

