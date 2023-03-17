#ifndef __NEUTRONTL_LOG_LOG_HPP__
#define __NEUTRONTL_LOG_LOG_HPP__

#include "BasicLog.hpp"

namespace ntl
{
    /// @brief 日志输出器
    /// @tparam m_LogItemType 日志对象类型
    /// @tparam m_ContainerType 容器类型
    template <typename m_LogItemType = LogItem, typename m_ContainerType = std::vector<m_LogItemType>>
    class Log : public BasicLog<m_LogItemType, m_ContainerType>
    {
    public:
        /// @brief 日志对象类型
        using LogItemType = m_LogItemType;

        /// @brief 容器类型
        using ContainerType = m_ContainerType;

        using SelfType = Log<LogItemType, ContainerType>;
        using ParentType = BasicLog<m_LogItemType, m_ContainerType>;

    public:
        Log() = default;
        explicit Log(bool auto_output);
        explicit Log(OutputStream *output);
        explicit Log(bool auto_output, OutputStream *output);
        explicit Log(const SelfType &from) = default;
        ~Log() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif