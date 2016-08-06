#include "stdafx.h"
#include "executor_impl.h"

executor_ptr create_executor()
{
    return make_shared<executor_impl>();
}


const char* executor_impl::mono_method_get_name(MonoMethod* method) 
{
    auto result = executor_base::mono_method_get_name(method);

    return result;
}

MonoClass* executor_impl::mono_class_from_name(MonoImage* image, const char* name_space, const char* name) 
{
    MonoClass* klass = executor_base::mono_class_from_name(image, name_space, name);
    
    image_desc_t &image_desc = stored_images_[image];
    class_desc_t &class_desc = image_desc.stored_classes[klass];

    class_desc.name = name;
    class_desc.name_space = name_space;

    return klass;
}
