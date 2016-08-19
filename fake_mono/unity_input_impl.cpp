#include "stdafx.h"
#include "unity_input_impl.h"
#include "mono_wrapper/functions.h"

mono_wrapper::functions_cptr mono_functions();


unity_input_ptr create_unity_input(unity_input_functions_cptr f)
{
    return make_shared<unity_input_impl>(f);
}


unity_input_impl::unity_input_impl(unity_input_functions_cptr f)
    : unity_input_base(f)
{
}



gboolean unity_input_impl::GetKeyString(MonoString* name) 
{
    char const *cname = mono_functions()->mono_string_to_utf8(name);
    return unity_input_base::GetKeyString(name);
}
