#ifndef __NEUTRONTL_MISC_INITIALIZEONLY_CPP__
#define __NEUTRONTL_MISC_INITIALIZEONLY_CPP__

#include <bits/move.h>
#include "InitializeOnly.hpp"

namespace ntl
{

    template <typename m_DataType>
    template <typename... ArgsType>
    InitializeOnly<m_DataType>::InitializeOnly(
        ArgsType &&...args)
        : m_data(std::forward<ArgsType>(args)...) {}

    template <typename m_DataType>
    const typename InitializeOnly<m_DataType>::DataType &
    InitializeOnly<m_DataType>::operator*() const
    {
        return m_data;
    }

    template <typename m_DataType>
    const typename InitializeOnly<m_DataType>::DataType &
    InitializeOnly<m_DataType>::operator->() const
    {
        return m_data;
    }

    template <typename m_DataType>
    InitializeOnly<m_DataType>::operator typename InitializeOnly<m_DataType>::DataType() const
    {
        return m_data;
    }

} // namespace ntl

#endif
