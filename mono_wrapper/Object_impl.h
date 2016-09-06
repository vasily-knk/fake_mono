#pragma once

#include "mono_wrapper/Object.h"
#include "mono_wrapper/object_base.h"

namespace mono_wrapper
{

struct Object_impl
    : virtual Object
{
    Object_impl(functions_cptr f, MonoObject *p);
    
    String_ptr ToString() override final;
    
    bool Equals(Object_ptr obj) override final;
    
    MonoObject *get_mono_object() const override final;
    char const *get_class_name() const override final;

public:
    object_base const &base() const;

protected:
    object_base base_;
};


}