#pragma once

#include "stdafx.h"
#include "mono_wrapper/MyWatcher.h"

#include "Object_impl.h"

namespace mono_wrapper
{

struct MyWatcher_impl
    : virtual Object_impl
    , virtual MyWatcher
{
    MyWatcher_impl(functions_cptr f, MonoObject *p);
    
    // String
public:
    void RegisterObject(GameObject_ptr o) override;
};


    
}

