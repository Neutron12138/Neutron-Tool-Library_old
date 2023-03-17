#ifndef __NEUTRONTL_LOG_LOG_CPP__
#define __NEUTRONTL_LOG_LOG_CPP__

#include "Log.hpp"

namespace ntl
{
    template <typename m_LogItemType, typename m_ContainerType>
    Log<m_LogItemType, m_ContainerType>::Log(
        bool auto_output)
        : Log<m_LogItemType, m_ContainerType>::ParentType(auto_output) {}

    template <typename m_LogItemType, typename m_ContainerType>
    Log<m_LogItemType, m_ContainerType>::Log(
        OutputStream *output)
        : Log<m_LogItemType, m_ContainerType>::ParentType(output) {}

    template <typename m_LogItemType, typename m_ContainerType>
    Log<m_LogItemType, m_ContainerType>::Log(
        bool auto_output,
        OutputStream *output)
        : Log<m_LogItemType, m_ContainerType>::ParentType(auto_output, output) {}

} // namespace ntl

#endif