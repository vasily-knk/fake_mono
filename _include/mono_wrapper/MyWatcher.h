#pragma once

#include "mono_wrapper/Object.h"

namespace mono_wrapper
{

struct MyWatcher
    : virtual Object
{
    virtual void RegisterObject(GameObject_ptr o) = 0;
};

MyWatcher_ptr wrap_MyWatcher(functions_cptr f, MonoObject *p);

} // namespace mono_wrapper