#pragma once

#include "mono_wrapper/Object.h"

namespace mono_wrapper
{

struct Transform
    : Object
{
    virtual Object_ptr get_position() = 0;
    virtual GameObject_ptr get_gameObject() = 0;
};

Transform_ptr wrap_Transform(functions_cptr f, MonoObject *p);

} // namespace mono_wrapper