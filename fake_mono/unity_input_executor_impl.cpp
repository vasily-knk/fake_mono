#include "stdafx.h"
#include "unity_input_executor_base.h"

namespace unity_input
{

executor_ptr create_executor(functions_cptr functions)
{
    return make_shared<executor_base>(functions);
}

} // namespace unity_input