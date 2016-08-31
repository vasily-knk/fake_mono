#pragma once

#include "mono_wrapper/Object.h"

namespace mono_wrapper
{

struct GameObject
    : Object
{
    virtual String_ptr get_name() = 0;
    virtual Transform_ptr get_transform() = 0;
    virtual int32_t GetInstanceID() = 0;
};

GameObject_ptr wrap_GameObject(functions_cptr f, MonoObject *p);

} // namespace mono_wrapper