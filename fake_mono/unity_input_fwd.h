#pragma once

namespace unity_input
{

struct functions_t;
typedef shared_ptr<functions_t const> functions_cptr;
typedef shared_ptr<functions_t> functions_ptr;

struct executor;
typedef shared_ptr<executor> executor_ptr;

} // namespace unity_input