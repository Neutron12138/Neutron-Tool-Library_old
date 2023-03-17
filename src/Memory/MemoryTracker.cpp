#ifndef __NEUTRONTL_MEMORY_MEMORYTRACKER_CPP__
#define __NEUTRoNTL_MEMORY_MEMORYTRACKER_CPP__

#include <bits/move.h>
#include "MemoryTracker.hpp"

namespace ntl
{
    template <typename m_ClassType>
    template <typename... ArgsType>
    MemoryTracker<m_ClassType>::MemoryTracker(
        ArgsType &&...args)
        : m_data(
              std::forward<ArgsType>(args)...) {}

    template <typename m_ClassType>
    MemoryTracker<m_ClassType>::MemoryTracker(
        const typename MemoryTracker<m_ClassType>::ClassType &from)
        : m_data(from) {}

    template <typename m_ClassType>
    MemoryTracker<m_ClassType>::operator typename MemoryTracker<m_ClassType>::ClassType()
    {
        return as();
    }

    template <typename m_ClassType>
    MemoryTracker<m_ClassType>::operator typename MemoryTracker<m_ClassType>::ClassType() const
    {
        return as();
    }

    template <typename m_ClassType>
    typename MemoryTracker<m_ClassType>::ClassType &
    MemoryTracker<m_ClassType>::as()
    {
        return *dynamic_cast<
            typename MemoryTracker<
                m_ClassType>::ClassType *>(
            this);
    }

    template <typename m_ClassType>
    const typename MemoryTracker<m_ClassType>::ClassType &
    MemoryTracker<m_ClassType>::as() const
    {
        return *dynamic_cast<
            typename MemoryTracker<
                m_ClassType>::ClassType *>(
            this);
    }

} // namespace ntl

#endif