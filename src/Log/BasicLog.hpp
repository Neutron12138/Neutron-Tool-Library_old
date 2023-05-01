#ifndef __NEUTRONTL_LOG_BASICLOG_HPP__
#define __NEUTRONTL_LOG_BASICLOG_HPP__

#include "../Base/Object.hpp"
#include "../Base/Type.hpp"
#include "LogItem.hpp"
#include "LogLevel.hpp"

namespace ntl
{
    /// @brief 日志输出器基类
    /// @tparam m_LogItemType 日志对象类型
    /// @tparam m_ContainerType 容器类型
    template <typename m_LogItemType = LogItem, typename m_ContainerType = std::vector<m_LogItemType>>
    class BasicLog : public Object
    {
    public:
        /// @brief 日志对象类型
        using LogItemType = m_LogItemType;

        /// @brief 容器类型
        using ContainerType = m_ContainerType;

        using SelfType = BasicLog<LogItemType, ContainerType>;
        using ParentType = Object;

    protected:
        /// @brief 日志的项目
        ContainerType m_items;

        /// @brief 是否自动输出
        bool m_auto_output = true;

#ifdef NEUTRONTL_CONFIG_USE_WCHAR
        /// @brief 输出流
        OutputStream *m_output = &std::wcout;
#else
        /// @brief 输出流
        OutputStream *m_output = &std::cout;
#endif

    public:
        BasicLog() = default;
        BasicLog(bool auto_output);
        BasicLog(OutputStream *output);
        BasicLog(bool auto_output, OutputStream *output);
        BasicLog(const SelfType &from) = default;
        ~BasicLog() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取所有日志
        /// @return 日志项目的容器
        const ContainerType &get_items() const;

        /// @brief 设置自动输出
        /// @param auto_output 是否自动输出
        /// @return 本对象
        SelfType &set_auto_output(bool auto_output);

        /// @brief 是否自动输出
        /// @return 是否自动输出
        bool is_auto_output() const;

        /// @brief 设置输出流
        /// @param output 输出流
        /// @return 本对象
        SelfType &set_output(OutputStream *output);

        /// @brief 获取输出流
        /// @return 输出流
        OutputStream *get_output();

    public:
        /// @brief 格式化日志
        /// @param item 日志项目
        /// @return 格式化后的结果
        virtual String format_log(const LogItem &item);

        /// @brief 向输出流中输出所有日志
        virtual void output_all();

        /// @brief 清空m_items里储存的所有日志
        virtual void clear_all();

    public:
        /// @brief 输出一条日志
        /// @param level 日志的等级
        /// @param title 日志的标题
        /// @param content 日志的内容
        virtual void log(LogLevel::LogLevel level, const String &title, const String &content);

        /// @brief 输出一条UNKNOWN等级的日志
        /// @param title 日志的标题
        /// @param content 日志的内容
        virtual void logu(const String &title, const String &content);

        /// @brief 输出一条INFO等级的日志
        /// @param title 日志的标题
        /// @param content 日志的内容
        virtual void logi(const String &title, const String &content);

        /// @brief 输出一条DEBUG等级的日志
        /// @param title 日志的标题
        /// @param content 日志的内容
        virtual void logd(const String &title, const String &content);

        /// @brief 输出一条WARNING等级的日志
        /// @param title 日志的标题
        /// @param content 日志的内容
        virtual void logw(const String &title, const String &content);

        /// @brief 输出一条ERROR等级的日志
        /// @param title 日志的标题
        /// @param content 日志的内容
        virtual void loge(const String &title, const String &content);
    };

} // namespace ntl

#endif