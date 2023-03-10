#ifndef __NEUTRONTL_REFLECTION_DETAILS_CPP__
#define __NEUTRONTL_REFLECTION_DETAILS_CPP__

#include "Details.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../Exception/CaughtException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    Details::Details(
        const FieldMap &fields,
        const MethodMap &methods,
        SizeT size)
        : m_fields(fields),
          m_methods(methods),
          m_size(size) {}

    const typename Details::FieldMap &
    Details::get_fields() const
    {
        return m_fields;
    }

    const typename Details::MethodMap &
    Details::get_methods() const
    {
        return m_methods;
    }

    SizeT
    Details::get_size() const
    {
        return m_size;
    }

    bool
    Details::has_field(
        const String &name) const
    {
        return m_fields.find(name) != m_fields.cend();
    }

    bool
    Details::has_method(
        const String &name) const
    {
        return m_methods.find(name) != m_methods.cend();
    }

    /*template <typename ReturnType>
    ReturnType &
    Details::get_field(
        const String &name) const
    {
        if (!has_field(name))
            throw OutOfRangeException(
                StringUtils::to_string(
                    NTL_STRING("Cannot find field: \""),
                    name,
                    NTL_STRING("\"")),
                NTL_STRING("template <typename ReturnType> ReturnType &Details::get_field(const String &name) const"));

        try
        {
            return m_fields.find(name)->second.of()
        }
        catch (const Exception &exception)
        {
            std::cerr << e.what() << '\n';
        }
    }

    template <typename ReturnType, typename... ArgsType>
    ReturnType
    Details::call_method(
        const String &name,
        ArgsType &&...args) const
    {
    }*/

} // namespace ntl

#endif