#pragma once

namespace mono_wrapper
{
    struct functions_t;
    typedef shared_ptr<functions_t const> functions_cptr;

    struct object_base;
    typedef shared_ptr<object_base> object_base_ptr;

    struct Object;
    typedef shared_ptr<Object> Object_ptr;
}