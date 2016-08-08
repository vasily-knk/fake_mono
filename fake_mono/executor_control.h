#pragma once

#include "stats.h"

struct executor_control
{
    virtual ~executor_control() {}

    virtual void go(task_t const &callback) = 0;
};

