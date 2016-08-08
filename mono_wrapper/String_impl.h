#pragma once

#include "stdafx.h"
#include "mono_wrapper/String.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct String_impl
    : String
{
    String_impl(functions_cptr f, MonoObject *p);
    
    // String
public:
    int32_t get_Length() override;
    String_ptr ToUpper() override;

public:
    char const *to_utf8() const override;

    // Object
public:
    String_ptr ToString()               override;
    bool Equals(Object_ptr obj)         override;
    MonoObject *get_mono_object() const override;

public:
    object_base const &base() const;

private:
    Object_impl super_;
};


}

