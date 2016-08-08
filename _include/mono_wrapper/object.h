#pragma once

#include "mono_wrapper_fwd.h"
#include "mono_wrapper/types.h"

namespace mono_wrapper
{

struct Object
{
    virtual ~Object() {};

    virtual Object_ptr ToString() = 0;
    virtual bool Equals(Object_ptr obj) = 0;

    virtual MonoObject *get_mono_object() const = 0;
};

Object_ptr wrap_Object(functions_cptr f, MonoObject *p);

} // namespace mono_wrapper