#pragma once

#include "mono_wrapper/Object.h"
#include "mono_wrapper/object_base.h"

namespace mono_wrapper
{

struct Object_impl
    : Object
{
    Object_impl(functions_cptr f, MonoObject *p);
    
    String_ptr ToString() override;
    
    bool Equals(Object_ptr obj) override;
    
    MonoObject *get_mono_object() const override;
    char const *get_class_name() const override;

public:
    object_base const &base() const;

protected:
    object_base base_;
};


}