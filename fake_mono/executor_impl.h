#pragma once

#include "executor_base.h"

struct executor_impl
    : executor_base
{
    const char* mono_method_get_name(MonoMethod* method) override;
    MonoClass* mono_class_from_name(MonoImage* image, const char* name_space, const char* name) override;

private:
    struct class_desc_t
    {
        string name;
        string name_space;
    };

    struct image_desc_t
    {
        std::map<MonoClass *, class_desc_t> stored_classes;
    };

private:
    std::map<MonoImage *, image_desc_t> stored_images_;
};