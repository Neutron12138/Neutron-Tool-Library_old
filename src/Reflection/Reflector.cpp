#ifndef __NEUTRONTL_REFLECTION_REFLECTOR_CPP__
#define __NEUTRONTL_REFLECTION_REFLECTOR_CPP__

#include "Reflector.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/InvalidArgumentException.hpp"

namespace ntl
{
    template <typename ClassType>
    const typename Reflector::DetailsPointer &
    Reflector::register_class(
        const String &name)
    {
        if (has_class(name))
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("Class (\""),
                    name,
                    NTL_STRING("\") already exists")),
                NTL_MAKE_STATEMENT_INFO("template <typename ClassType> const typename Reflector::DetailsPointer &Reflector::register_class(const String &name)"));

        return register_class(
            name,
            ClassType::get_reflection_details());
    }

    const typename Reflector::DetailsPointer &
    Reflector::register_class(
        const String &name,
        const Details &details)
    {
        if (has_class(name))
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("Class (\""),
                    name,
                    NTL_STRING("\") already exists")),
                NTL_MAKE_STATEMENT_INFO("const typename Reflector::DetailsPointer &Reflector::register_class(const String &name,const Details &details)"));

        typename Reflector::DetailsPointer pointer(
            new Details(
                details));

        return register_class(name, pointer);
    }

    const typename Reflector::DetailsPointer &
    Reflector::register_class(
        const String &name,
        const typename Reflector::DetailsPointer &details)
    {
        if (has_class(name))
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("Class (\""),
                    name,
                    NTL_STRING("\") already exists")),
                NTL_MAKE_STATEMENT_INFO("const typename Reflector::DetailsPointer &Reflector::register_class(const String &name,const typename Reflector::DetailsPointer &details)"));

        m_classes.insert(
            Reflector::ClassMap::value_type(
                name,
                details));

        return m_classes.at(name);
    }

    const typename Reflector::DetailsPointer &
    Reflector::get_class(
        const String &name) const
    {
        if (!has_class(name))
            throw OutOfRangeException(
                StringUtils::to_string(
                    NTL_STRING("Class not found: \""),
                    name,
                    NTL_STRING("\"")),
                NTL_MAKE_STATEMENT_INFO("const typename Reflector::DetailsPointer &Reflector::get_class(const String &name) const"));

        return m_classes.at(name);
    }

    bool
    Reflector::has_class(
        const String &name) const
    {
        return m_classes.find(name) != m_classes.cend();
    }

} // namespace ntl

#endif