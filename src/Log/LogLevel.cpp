#ifndef __NEUTRONTL_LOG_LOGLEVEL_CPP__
#define __NEUTRONTL_LOG_LOGLEVEL_CPP__

#include "LogLevel.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    String
    get_log_level_string(LogLevel::LogLevel level)
    {
        String result;
        switch (level)
        {
        case LogLevel::LogLevel::Unknown:
            result = NTL_STRING("Unknown");
            break;

        case LogLevel::LogLevel::Info:
            result = NTL_STRING("Info");
            break;

        case LogLevel::LogLevel::Debug:
            result = NTL_STRING("Debug");
            break;

        case LogLevel::LogLevel::Warning:
            result = NTL_STRING("Warning");
            break;

        case LogLevel::LogLevel::Error:
            result = NTL_STRING("Error");
            break;

        default:
            result = NTL_STRING("Undefined");
            break;
        }
        return result;
    }

    LogLevel::LogLevel
    get_log_level_enum(const String &level)
    {
        LogLevel::LogLevel result;
        if (level == NTL_STRING("Info"))
        {
            result = LogLevel::LogLevel::Info;
        }
        else if (level == NTL_STRING("Debug"))
        {
            result = LogLevel::LogLevel::Debug;
        }
        else if (level == NTL_STRING("Warning"))
        {
            result = LogLevel::LogLevel::Warning;
        }
        else if (level == NTL_STRING("Error"))
        {
            result = LogLevel::LogLevel::Error;
        }
        else
        {
            result = LogLevel::LogLevel::Unknown;
        }
        return result;
    }

} // namespace ntl

#endif