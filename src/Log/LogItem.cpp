#ifndef __NEUTRONTL_LOG_LOGITEM_CPP__
#define __NEUTRONTL_LOG_LOGITEM_CPP__

#include "LogItem.hpp"

namespace ntl
{
    LogItem::LogItem(LogLevel::LogLevel level,
                     const String &title,
                     const String &content)
        : m_level(level),
          m_title(title),
          m_content(content)
    {
        time_t now = time(nullptr);
        m_time = localtime(&now);
    }

    const std::tm *
    LogItem::get_time() const
    {
        return m_time;
    }

    LogLevel::LogLevel
    LogItem::get_level() const
    {
        return m_level;
    }

    const String &
    LogItem::get_title() const
    {
        return m_title;
    }

    const String &
    LogItem::get_content() const
    {
        return m_content;
    }

} // namespace ntl

#endif