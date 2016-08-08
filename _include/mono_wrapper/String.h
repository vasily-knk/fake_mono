#pragma once

#include "mono_wrapper/Object.h"

namespace mono_wrapper
{

struct String
    : Object
{
    virtual int32_t get_Length() = 0;
    virtual String_ptr ToUpper() = 0;

    virtual char const *to_utf8() const = 0;
};

String_ptr wrap_String(functions_cptr f, MonoObject *p);
String_ptr new_String(functions_cptr f, char const *s);

} // namespace mono_wrapper