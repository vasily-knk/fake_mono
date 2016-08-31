#pragma once

namespace mono_wrapper
{
    struct functions_t;
    typedef shared_ptr<functions_t const> functions_cptr;

    struct object_base;
    typedef shared_ptr<object_base> object_base_ptr;

    struct Object;
    typedef shared_ptr<Object> Object_ptr;
    struct String;
    typedef shared_ptr<String> String_ptr;
    struct Array;
    typedef shared_ptr<Array> Array_ptr;

    struct GameObject;
    typedef shared_ptr<GameObject> GameObject_ptr;
    struct Transform;
    typedef shared_ptr<Transform> Transform_ptr;
    struct Vector3;
}