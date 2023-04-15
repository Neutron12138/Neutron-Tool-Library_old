#ifndef __NEUTRONTL_BASE_NAMEDOBJECT_CPP__
#define __NEUTRONTL_BASE_NAMEDOBJECT_CPP__

#include "NamedObject.hpp"

namespace ntl
{
    NamedObject::NamedObject(
        const String &name)
        : m_name(name) {}

    const String &
    NamedObject::get_name() const
    {
        return m_name;
    }

    typename NamedObject::SelfType &
    NamedObject::set_name(
        const String &name)
    {
        m_name = name;
        return *this;
    }
} // namespace ntl

#endif