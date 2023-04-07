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
        return m_value != another.m_value;
    }

    template <typename m_ValueType>
    bool
    BasicEnumeration<m_ValueType>::operator>(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return m_value > another.m_value;
    }

    template <typename m_ValueType>
    bool
    BasicEnumeration<m_ValueType>::operator>=(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return m_value >= another.m_value;
    }

    template <typename m_ValueType>
    bool
    BasicEnumeration<m_ValueType>::operator<(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return m_value < another.m_value;
    }

    template <typename m_ValueType>
    bool
    BasicEnumeration<m_ValueType>::operator<=(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return m_value <= another.m_value;
    }

    template <typename m_ValueType>
    typename BasicEnumeration<m_ValueType>::SelfType
    BasicEnumeration<m_ValueType>::operator|(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return SelfType(m_value | another.m_value);
    }

    template <typename m_ValueType>
    typename BasicEnumeration<m_ValueType>::SelfType
    BasicEnumeration<m_ValueType>::operator&(
        const typename BasicEnumeration<m_ValueType>::SelfType &another) const
    {
        return SelfType(m_value & another.m_value);
    }

    template <typename m_ValueType>
    typename BasicEnumeration<m_ValueType>::SelfType &
    BasicEnumeration<m_ValueType>::operator|=(
        const typename BasicEnumeration<m_ValueType>::SelfType &another)
    {
        *this = *this | another;
        return *this;
    }

    template <typename m_ValueType>
    typename BasicEnumeration<m_ValueType>::SelfType &
    BasicEnumeration<m_ValueType>::operator&=(
        const typename BasicEnumeration<m_ValueType>::SelfType &another)
    {
        *this = *this & another;
        return *this;
    }

    template <typename m_ValueType>
    BasicEnumeration<m_ValueType>::operator BasicEnumeration<m_ValueType>::ValueType() const
    {
        return m_value;
    }

    template <typename m_ValueType>
    BasicEnumeration<m_ValueType>::operator bool() const
    {
        return !is_zero();
    }

    template <typename m_ValueType>
    const typename BasicEnumeration<m_ValueType>::ValueType &
    BasicEnumeration<m_ValueType>::get_value() const
    {
        return m_value;
    }

    template <typename m_ValueType>
    bool
    BasicEnumeration<m_ValueType>::is_zero() const
    {
        return m_value == 0;
    }

    //
    // 模板特化
    //

    BasicEnumeration<String>::BasicEnumeration(
        const typename BasicEnumeration<String>::ValueType &value)
        : m_value(value) {}

    bool
    BasicEnumeration<String>::operator==(
        const typename BasicEnumeration<String>::SelfType &another) const
    {
        return m_value == another.m_value;
    }

    bool
    BasicEnumeration<String>::operator!=(
        const typename BasicEnumeration<String>::SelfType &another) const
    {
        return m_value != another.m_value;
    }

    BasicEnumeration<String>::operator BasicEnumeration<String>::ValueType() const
    {
        return m_value;
    }

    const typename BasicEnumeration<String>::ValueType &
    BasicEnumeration<String>::get_value() const
    {
        return m_value;
    }

    //
    // 重载函数
    //

    template <typename ValueType>
    OutputStream &
    operator<<(
        OutputStream &os,
        const BasicEnumeration<ValueType> &enumeration)
    {
        os << enumeration.get_value();
        return os;
    }

} // namespace ntl

#endif