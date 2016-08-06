#include "stdafx.h"
#include "log.h"

namespace
{
    std::ofstream g_log_stream("fake_mono_log.txt");
};

std::ostream &log_stream()
{
    return g_log_stream;
}

void log_message(char const *msg)
{
    g_log_stream << msg << "\n";
    g_log_stream.flush();
}

