#pragma once

#include "stats.h"

struct executor_control;

namespace monitor
{


typedef std::function<void()> post_f;
typedef std::function<void(post_f const&)> post_service_f;

void run(executor_control *executor_control);
void post(post_f const &f);

void print(string const &str);

} // namespace monitor