#ifndef __NEUTRONTL_LOG_LOGITEM_HPP__
#define __NEUTRONTL_LOG_LOGITEM_HPP__

#include <ctime>
#include "LogLevel.hpp"
#include "../Base/Object.hpp"
#include "../Base/Type.hpp"

namespace ntl
{
    /// @brief 日志项目
    class LogItem : public Object
    {
    public:
        using SelfType = LogItem;
        using ParentType = Object;

    protected:
        /// @brief 时间
        std::tm *m_time;

        /// @brief 等级
        LogLevel::LogLevel m_level;

        /// @brief 标题
        String m_title;

        /// @brief 内容
        String m_content;

    public:
        explicit LogItem(LogLevel::LogLevel level, const String &title, const String &content);
        explicit LogItem(const LogItem &from) = default;
        ~LogItem() override = default;

    public:
        LogItem &operator=(const LogItem &from) = default;

    public:
        /// @brief 获取日志的时间
        /// @return 日志的时间
        const std::tm *get_time() const;

        /// @brief 获取日志的等级
        /// @return 日志的等级
        LogLevel::LogLevel get_level() const;

        /// @brief 获取日志的标题
        /// @return 日志的标题
        const String &get_title() const;

        /// @brief 获取日志的内容
        /// @return 日志的内容
        const String &get_content() const;
    };

} // namespace ntl

#endif