#pragma once

#include "stats.h"

struct executor_control
{
    virtual ~executor_control() {}

    virtual void init_watcher() = 0;
};

