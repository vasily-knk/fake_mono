#pragma once

#include "stats.h"

namespace monitor
{

void run();

typedef std::function<void()> post_f;
void post(post_f const &f);

void update_stats(stats_t const &st);

} // namespace monitor