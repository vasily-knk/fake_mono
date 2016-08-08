#pragma once

#include "stdafx.h"
#include "mono_wrapper/Array.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct Array_impl
    : Array
{
    Array_impl(functions_cptr f, MonoObject *p);
    
    // Array
public:
    int32_t get_Length() override;
    Object_ptr Get(int32_t index) override;

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

