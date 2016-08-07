#pragma once

#include "stats.h"

namespace monitor
{


typedef std::function<void()> post_f;
typedef std::function<void(post_f const&)> post_service_f;

void run(post_service_f const &post_service);
void post(post_f const &f);

void print(string const &str);

} // namespace monitor