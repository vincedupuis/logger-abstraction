#include "SpdlogLogger.h"
#include <spdlog/spdlog.h>

ILogger* ILogger::instance()
{
    static SpdlogLogger logger;
    return &logger;
}

inline void log(const std::source_location& sl, spdlog::level::level_enum level, const char* message)
{
    spdlog::log(
        spdlog::source_loc{
            sl.file_name(), static_cast<int>(sl.line()), sl.function_name()
        },
        level,
        message);
}

inline SpdlogLogger::SpdlogLogger()
{
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%f [%l] [%t] %v (%s:%#)");
}

inline void SpdlogLogger::trace(std::source_location sl, const char* message)
{
    log(sl, spdlog::level::trace, message);
}

inline void SpdlogLogger::debug(std::source_location sl, const char* message)
{
    log(sl, spdlog::level::debug, message);
}

inline void SpdlogLogger::info(std::source_location sl, const char* message)
{
    log(sl, spdlog::level::info, message);
}

inline void SpdlogLogger::warn(std::source_location sl, const char* message)
{
    log(sl, spdlog::level::warn, message);
}

inline void SpdlogLogger::error(std::source_location sl, const char* message)
{
    log(sl, spdlog::level::err, message);
}

inline void SpdlogLogger::fatal(std::source_location sl, const char* message)
{
    log(sl, spdlog::level::critical, message);
}
