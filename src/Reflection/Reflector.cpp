#ifndef __NEUTRONTL_REFLECTION_REFLECTOR_CPP__
#define __NEUTRONTL_REFLECTION_REFLECTOR_CPP__

#include "Reflector.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename ClassType>
    const typename Reflector::DetailsPointer &
    Reflector::register_class(
        const String &name)
    {
        typename Reflector::DetailsPointer pointer(
            new Details(
                ClassType::get_reflection_details()));

        m_classes.insert(
            Reflector::ClassMap::value_type(
                name,
                pointer));

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
                NTL_STRING("const typename Reflector::DetailsPointer &Reflector::get_class(const String &name) const"));

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