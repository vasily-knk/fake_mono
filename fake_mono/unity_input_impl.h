#pragma once

#include "unity_input_base.h"

struct unity_input_impl
    : unity_input_base
{
    unity_input_impl(unity_input_functions_cptr f);

    gboolean GetKeyString(MonoString* name) override;
};