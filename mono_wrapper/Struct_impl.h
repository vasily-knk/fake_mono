#pragma once

#include "stdafx.h"
#include "mono_wrapper/Struct.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct Struct_impl
    : Struct
{
    Struct_impl(functions_cptr f, MonoObject *p);
    
public:
    void const *raw_ptr() const override;

    // Object
public:
    String_ptr ToString()               override;
    bool Equals(Object_ptr obj)         override;
    MonoObject *get_mono_object() const override;
    char const *get_class_name() const override;

public:
    object_base const &base() const;

private:
    Object_impl super_;
};


}

