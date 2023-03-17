#ifndef __NEUTRONTL_MEMORY_DEFAULTMEMORYTRACKER_CPP__
#define __NEUTRoNTL_MEMORY_DEFAULTMEMORYTRACKER_CPP__

#include <typeinfo>
#include "DefaultMemoryTracker.hpp"
#include "../Instances.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_ClassType>
    long long DefaultMemoryTracker<m_ClassType>::m_count = 0;

    template <typename m_ClassType>
    DefaultMemoryTracker<m_ClassType>::DefaultMemoryTracker()
    {
        on_construction();
    }

    template <typename m_ClassType>
    template <typename... ArgsType>
    DefaultMemoryTracker<m_ClassType>::DefaultMemoryTracker(
        ArgsType &&...args)
        : DefaultMemoryTracker<m_ClassType>::ParentType(args...)
    {
        on_construction();
    }

    template <typename m_ClassType>
    DefaultMemoryTracker<m_ClassType>::DefaultMemoryTracker(
        const typename DefaultMemoryTracker<m_ClassType>::ClassType &from)
        : DefaultMemoryTracker<m_ClassType>::ParentType(from)
    {
        on_construction();
    }

    template <typename m_ClassType>
    DefaultMemoryTracker<m_ClassType>::DefaultMemoryTracker(
        const typename DefaultMemoryTracker<m_ClassType>::SelfType &from)
    {
        on_construction();
    }

    template <typename m_ClassType>
    DefaultMemoryTracker<m_ClassType>::~DefaultMemoryTracker()
    {
        on_destruction();
    }

    template <typename m_ClassType>
    void
    DefaultMemoryTracker<m_ClassType>::on_construction()
    {
        log.logi(
            NTL_STRING("Default Memory Tracker"),
            StringUtils::to_string(
                NTL_STRING("The type \""),
                typeid(m_ClassType).name(),
                NTL_STRING("\" is constructed at "),
                this));

        m_count++;
    }

    template <typename m_ClassType>
    void
    DefaultMemoryTracker<m_ClassType>::on_destruction()
    {
        log.logi(
            NTL_STRING("Default Memory Tracker"),
            StringUtils::to_string(
                NTL_STRING("The type \""),
                typeid(m_ClassType).name(),
                NTL_STRING("\" is destructed at "),
                this));

        m_count--;
    }

    template <typename m_ClassType>
    long long
    DefaultMemoryTracker<m_ClassType>::get_count()
    {
        return m_count;
    }

} // namespace ntl

#endif