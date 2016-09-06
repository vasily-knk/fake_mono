#pragma once

#include "stdafx.h"
#include "mono_wrapper/GameObject.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct GameObject_impl
    : virtual Object_impl
    , virtual GameObject
{
    GameObject_impl(functions_cptr f, MonoObject *p);
    
    // GameObject
public:
    String_ptr get_name() override;
    Transform_ptr get_transform() override;
    int32_t GetInstanceID() override;
};


}

