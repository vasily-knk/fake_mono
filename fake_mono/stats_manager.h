#pragma once

#include "mono_wrapper/mono_wrapper_fwd.h"

struct stats_manager
{
    virtual ~stats_manager() {}

    virtual void set_position(mono_wrapper::Transform_ptr transform, mono_wrapper::Vector3 const *pos) = 0;
};

typedef shared_ptr<stats_manager> stats_manager_ptr;
stats_manager_ptr stats_manager_instance();