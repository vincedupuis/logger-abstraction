#pragma once

#include "ILogger.h"

class SpdlogLogger final : public ILogger
{
public:
    SpdlogLogger();

    void trace(std::source_location sl, const char* message) override;
    void debug(std::source_location sl, const char* message) override;
    void info(std::source_location sl, const char* message) override;
    void warn(std::source_location sl, const char* message) override;
    void error(std::source_location sl, const char* message) override;
    void fatal(std::source_location sl, const char* message) override;
};
