#pragma once

#include "functions.h"
#include "mono_wrapper_fwd.h"

namespace mono_wrapper
{

struct class_desc_t
{
    class_desc_t(functions_cptr f, MonoClass *p)
        : f_(f)
        , p_(p)
    {}


private:
    functions_cptr f_;
    MonoClass *p_;
};


} // namespace mono_wrapper