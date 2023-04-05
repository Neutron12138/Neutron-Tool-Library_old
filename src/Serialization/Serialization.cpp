#ifndef __NEUTRONTL_SERIALIZATION_SERIALIZATION_CPP__
#define __NEUTRONTL_SERIALIZATION_SERIALIZATION_CPP__

#include "Serialization.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/InvalidArgumentException.hpp"

namespace ntl
{
    Serialization::Serialization(
        const String &serialization)
        : m_serialization(serialization) {}

    bool
    Serialization::operator>(
        const typename Serialization::SelfType &another)
    {
        return m_serialization > another.m_serialization;
    }

    bool
    Serialization::operator<(
        const typename Serialization::SelfType &another)
    {
        return m_serialization < another.m_serialization;
    }

    bool
    Serialization::operator>=(
        const typename Serialization::SelfType &another)
    {
        return m_serialization >= another.m_serialization;
    }

    bool
    Serialization::operator<=(
        const typename Serialization::SelfType &another)
    {
        return m_serialization <= another.m_serialization;
    }

    bool
    Serialization::operator==(
        const typename Serialization::SelfType &another)
    {
        return m_serialization == another.m_serialization;
    }

    bool
    Serialization::operator!=(
        const typename Serialization::SelfType &another)
    {
        return m_serialization != another.m_serialization;
    }

    Serialization::operator String()
    {
        return m_serialization;
    }

    Serialization::operator String() const
    {
        return m_serialization;
    }

    const ntl::String &
    Serialization::get_serialization() const
    {
        return m_serialization;
    }

    Serialization::SelfType &
    Serialization::set_serialization(
        const ntl::String &serialization)
    {
        m_serialization = serialization;
        return *this;
    }

    OutputStream &
    operator<<(
        OutputStream &os,
        const Serialization &serialization)
    {
        os << serialization.get_serialization();
        return os;
    }

} // namespace ntl

#endif