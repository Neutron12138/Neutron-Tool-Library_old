#ifndef __NEUTRONTL_TYPEINFO_TYPE_CPP__
#define __NEUTRONTL_TYPEINFO_TYPE_CPP__

#include "Type.hpp"

namespace ntl
{
    Type::Type(
        const std::type_info &info)
        : m_info(info) {}

    Type::Type(
        const String &name,
        const std::type_info &info)
        : m_name(name),
          m_info(info) {}

    bool
    Type::operator==(
        const typename Type::SelfType &another) const
    {
        return is_info_equal(another);
    }

    bool
    Type::operator!=(
        const typename Type::SelfType &another) const
    {
        return !operator==(another);
    }

    const String &
    Type::get_name() const
    {
        return m_name;
    }

    const std::type_info &
    Type::get_info() const
    {
        return m_info;
    }

    bool
    Type::is_name_equal(
        const typename Type::SelfType &another) const
    {
        return m_name == another.m_name;
    }

    bool
    Type::is_info_equal(
        const typename Type::SelfType &another) const
    {
        return m_info == another.m_info;
    }

    template <typename T>
    Type
    get_type(
        const String &name)
    {
        return Type(
            name,
            typeid(T));
    }

    template <typename T>
    Type
    get_type()
    {
        return Type(
            typeid(T));
    }

    template <typename T>
    Type
    get_type(
        const T &)
    {
        return get_type<T>();
    }

} // namespace ntl

#endif