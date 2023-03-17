#ifndef __NEUTRONTL_LOG_BASICLOG_CPP__
#define __NEUTRONTL_LOG_BASICLOG_CPP__

#include "BasicLog.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_LogItemType, typename m_ContainerType>
    BasicLog<m_LogItemType, m_ContainerType>::BasicLog(
        bool auto_output)
        : m_auto_output(auto_output) {}

    template <typename m_LogItemType, typename m_ContainerType>
    BasicLog<m_LogItemType, m_ContainerType>::BasicLog(
        OutputStream *output)
        : m_output(output) {}

    template <typename m_LogItemType, typename m_ContainerType>
    BasicLog<m_LogItemType, m_ContainerType>::BasicLog(
        bool auto_output,
        OutputStream *output)
        : m_auto_output(auto_output),
          m_output(output) {}

    template <typename m_LogItemType, typename m_ContainerType>
    const typename BasicLog<m_LogItemType, m_ContainerType>::ContainerType &
    BasicLog<m_LogItemType, m_ContainerType>::get_items() const
    {
        return m_items;
    }

    template <typename m_LogItemType, typename m_ContainerType>
    typename BasicLog<m_LogItemType, m_ContainerType>::SelfType &
    BasicLog<m_LogItemType, m_ContainerType>::set_auto_output(
        bool auto_output)
    {
        m_auto_output = auto_output;
        return *this;
    }

    template <typename m_LogItemType, typename m_ContainerType>
    bool
    BasicLog<m_LogItemType, m_ContainerType>::is_auto_output() const
    {
        return m_auto_output;
    }

    template <typename m_LogItemType, typename m_ContainerType>
    typename BasicLog<m_LogItemType, m_ContainerType>::SelfType &
    BasicLog<m_LogItemType, m_ContainerType>::set_output(
        OutputStream *output)
    {
        m_output = output;
        return *this;
    }

    template <typename m_LogItemType, typename m_ContainerType>
    OutputStream *
    BasicLog<m_LogItemType, m_ContainerType>::get_output()
    {
        return m_output;
    }

    template <typename m_LogItemType, typename m_ContainerType>
    String
    BasicLog<m_LogItemType, m_ContainerType>::format_log(
        const LogItem &item)
    {
        StringStream sstr;
        const std::tm *tm = item.get_time();
        sstr << NTL_STRING("--------------------") << std::endl
             << NTL_STRING("Time:") << asctime(tm)
             << NTL_STRING("Level:") << get_log_level_string(item.get_level()) << std::endl
             << NTL_STRING("Title:") << item.get_title() << std::endl
             << NTL_STRING("Content:") << item.get_content() << std::endl
             << std::endl;
        return sstr.str();
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::output_all()
    {
        for (size_t i = 0; i < m_items.size(); i++)
        {
            *m_output << format_log(m_items.at(i));
        }
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::clear_all()
    {
        m_items.clear();
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::log(
        LogLevel::LogLevel level,
        const String &title,
        const String &content)
    {
        LogItem item(level, title, content);
        m_items.push_back(item);
        if (m_auto_output)
            *m_output << format_log(item);
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::logu(
        const String &title,
        const String &content)
    {
        log(
            LogLevel::LogLevel::Unknown,
            title,
            content);
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::logi(
        const String &title,
        const String &content)
    {
        log(
            LogLevel::LogLevel::Info,
            title,
            content);
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::logd(
        const String &title,
        const String &content)
    {
        log(
            LogLevel::LogLevel::Debug,
            title,
            content);
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::logw(
        const String &title,
        const String &content)
    {
        log(
            LogLevel::LogLevel::Warning,
            title,
            content);
    }

    template <typename m_LogItemType, typename m_ContainerType>
    void
    BasicLog<m_LogItemType, m_ContainerType>::loge(
        const String &title,
        const String &content)
    {
        log(
            LogLevel::LogLevel::Error,
            title,
            content);
    }

} // namespace ntl

#endif