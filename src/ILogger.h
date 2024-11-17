#pragma once

#include <source_location>
#include <fmt/core.h>

#define logTRACE(...) ILogger::instance()->trace(std::source_location::current(), fmt::format(__VA_ARGS__).c_str())
#define logDEBUG(...) ILogger::instance()->debug(std::source_location::current(), fmt::format(__VA_ARGS__).c_str())
#define logINFO(...) ILogger::instance()->info(std::source_location::current(), fmt::format(__VA_ARGS__).c_str())
#define logWARN(...) ILogger::instance()->warn(std::source_location::current(), fmt::format(__VA_ARGS__).c_str())
#define logERROR(...) ILogger::instance()->error(std::source_location::current(), fmt::format(__VA_ARGS__).c_str())
#define logFATAL(...) ILogger::instance()->fatal(std::source_location::current(), fmt::format(__VA_ARGS__).c_str())

class ILogger
{
public:
    virtual ~ILogger() = default;

    static ILogger* instance();

    virtual void trace(std::source_location, const char* message) = 0;
    virtual void debug(std::source_location, const char* message) = 0;
    virtual void info(std::source_location, const char* message) = 0;
    virtual void warn(std::source_location, const char* message) = 0;
    virtual void error(std::source_location, const char* message) = 0;
    virtual void fatal(std::source_location, const char* message) = 0;
};
