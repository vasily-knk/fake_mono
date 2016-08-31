#pragma once

#include "stdafx.h"
#include "mono_wrapper/GameObject.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct GameObject_impl
    : GameObject
{
    GameObject_impl(functions_cptr f, MonoObject *p);
    
    // GameObject
public:
    String_ptr get_name() override;
    Transform_ptr get_transform() override;
    int32_t GetInstanceID() override;

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

