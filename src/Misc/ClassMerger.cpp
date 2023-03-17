#ifndef __NEUTRONTL_MISC_CLASSMERGER_CPP__
#define __NEUTRONTL_MISC_CLASSMERGER_CPP__

#include <bits/move.h>
#include "ClassMerger.hpp"

namespace ntl
{
    template <typename m_ClassType>
    template <typename... ArgsType>
    ClassMerger<m_ClassType>::ClassMerger(
        ArgsType &&...args)
        : ClassMerger<m_ClassType>::ParentType(
              std::forward<ArgsType>(args)...) {}

    template <typename m_ClassType>
    ClassMerger<m_ClassType>::ClassMerger(
        const typename ClassMerger<m_ClassType>::ClassType &from)
        : ClassMerger<m_ClassType>::ParentType(from) {}

    template <typename m_ClassType>
    ClassMerger<m_ClassType>::operator typename ClassMerger<m_ClassType>::ClassType()
    {
        return as();
    }

    template <typename m_ClassType>
    ClassMerger<m_ClassType>::operator typename ClassMerger<m_ClassType>::ClassType() const
    {
        return as();
    }

    template <typename m_ClassType>
    typename ClassMerger<m_ClassType>::ClassType &
    ClassMerger<m_ClassType>::as()
    {
        return *dynamic_cast<
            typename ClassMerger<
                m_ClassType>::ClassType *>(
            this);
    }

    template <typename m_ClassType>
    const typename ClassMerger<m_ClassType>::ClassType &
    ClassMerger<m_ClassType>::as() const
    {
        return *dynamic_cast<
            typename ClassMerger<
                m_ClassType>::ClassType *>(
            this);
    }

} // namespace ntl

#endif