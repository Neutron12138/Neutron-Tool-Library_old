#ifndef __NEUTRONTL_MISC_ENUMERATION_CPP__
#define __NEUTRONTL_MISC_ENUMERATION_CPP__

#include "Enumeration.hpp"

namespace ntl
{
    template <typename m_ValueType>
    BasicEnumeration<m_ValueType>::BasicEnumeration(
        const typename BasicEnumeration<m_ValueType>::ValueType &value)
        : m_value(value) {}

    template <typename m_ValueType>
    bool
    BasicEnumeration<m_ValueType>::operator==(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return m_value == another.m_value;
    }

    template <typename m_ValueType>
    bool
    BasicEnumeration<m_ValueType>::operator!=(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return !operator==(another);
    }

    template <typename m_ValueType>
    BasicEnumeration<m_ValueType>::operator BasicEnumeration<m_ValueType>::ValueType() const
    {
        return m_value;
    }

    template <typename m_ValueType>
    const typename BasicEnumeration<m_ValueType>::ValueType &
    BasicEnumeration<m_ValueType>::get_value() const
    {
        return m_value;
    }

} // namespace ntl

#endif