#include "stdafx.h"
#include "MyWatcher_impl.h"
#include "mono_wrapper/String.h"
#include "mono_wrapper/GameObject.h"

namespace mono_wrapper
{

MyWatcher_impl::MyWatcher_impl(functions_cptr f, MonoObject *p)
    : Object_impl(f, p)
{}


void MyWatcher_impl::RegisterObject(GameObject_ptr o)
{
    auto f = base().get_f();
    auto klass = f->mono_object_get_class(o->get_mono_object());
    char const *class_name = f->mono_class_get_name(klass);

    MonoMethod *m = base().get_method("RegisterObject", 1);
    void *args[] = { o->get_mono_object() };
    
    MonoObject *exc = nullptr;
    base().invoke_method_ex(m, args, &exc);
    if (exc)
    {
        auto exc_ptr = mono_wrapper::wrap_Object(f, exc);
        auto msg = exc_ptr->ToString()->to_utf8();
    }
}

MyWatcher_ptr wrap_MyWatcher(functions_cptr f, MonoObject *p)
{
    return make_shared<MyWatcher_impl>(f, p);
}


} // namespace mono_wrapper