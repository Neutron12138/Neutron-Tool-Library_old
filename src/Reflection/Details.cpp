#ifndef __NEUTRONTL_REFLECTION_DETAILS_CPP__
#define __NEUTRONTL_REFLECTION_DETAILS_CPP__

#include "Details.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../Exception/CaughtException.hpp"
#include "../String/StringUtils.hpp"
#include "../Misc/ContainerOperation.hpp"
#include "../Exception/InvalidArgumentException.hpp"

namespace ntl
{
    String Details::get_reflection_details_name = NTL_STRING("get_reflection_details()");
    String Details::construction_name = NTL_STRING("<construction>");
    String Details::destruction_name = NTL_STRING("<destruction>");

    Details::Details(
        SizeT size)
        : m_size(size) {}

    Details::Details(
        SizeT size,
        const NonStaticFieldMap &nonstatic_fields,
        const StaticFieldMap &static_fields,
        const NonStaticMethodMap &nonstatic_methods,
        const StaticMethodMap &static_methods)
        : m_size(size),
          m_nonstatic_fields(nonstatic_fields),
          m_static_fields(static_fields),
          m_nonstatic_methods(nonstatic_methods),
          m_static_methods(static_methods) {}

    SizeT
    Details::get_size() const
    {
        return m_size;
    }

    const typename Details::NonStaticFieldMap &
    Details::get_nonstatic_fields() const
    {
        return m_nonstatic_fields;
    }

    const typename Details::StaticFieldMap &
    Details::get_static_fields() const
    {
        return m_static_fields;
    }

    const typename Details::NonStaticMethodMap &
    Details::get_nonstatic_methods() const
    {
        return m_nonstatic_methods;
    }

    const typename Details::StaticMethodMap &
    Details::get_static_methods() const
    {
        return m_static_methods;
    }

    bool
    Details::has_field(
        const String &name) const
    {
        // 是否在非静态属性里
        bool in_nonstatic = m_nonstatic_fields.find(name) != m_nonstatic_fields.cend();
        // 是否在静态属性里
        bool in_static = m_static_fields.find(name) != m_static_fields.cend();

        // 同时存在于静态与非静态属性中
        if (in_nonstatic && in_static)
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("Field \""),
                    name,
                    NTL_STRING("\" has a duplicate name")),
                NTL_STRING("bool Details::has_field(const String &name) const"));
        // 存在于静态或非静态属性中
        else if (in_nonstatic || in_static)
            return true;

        return false;
    }

    bool
    Details::has_method(
        const String &name) const
    {
        // 是否在非静态方法里
        bool in_nonstatic = m_nonstatic_methods.find(name) != m_nonstatic_methods.cend();
        // 是否在静态方法里
        bool in_static = m_static_methods.find(name) != m_static_methods.cend();

        // 同时存在于静态与非静态方法中
        if (in_nonstatic && in_static)
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("Method \""),
                    name,
                    NTL_STRING("\" has a duplicate name")),
                NTL_MAKE_STATEMENT_INFO("bool Details::has_method(const String &name) const"));
        // 存在于静态或非静态方法中
        else if (in_nonstatic || in_static)
            return true;

        return false;
    }

    Details
    Details::merge(
        const Details &another)
    {
        typename Details::NonStaticFieldMap nonstatic_fields = ContainerOperation::merge(m_nonstatic_fields, another.get_nonstatic_fields());
        typename Details::StaticFieldMap static_fields = ContainerOperation::merge(m_static_fields, another.get_static_fields());
        typename Details::NonStaticMethodMap nonstatic_methods = ContainerOperation::merge(m_nonstatic_methods, another.get_nonstatic_methods());
        typename Details::StaticMethodMap static_methods = ContainerOperation::merge(m_static_methods, another.get_static_methods());

        return Details(
            m_size,
            nonstatic_fields,
            static_fields,
            nonstatic_methods,
            static_methods);
    }

    template <typename... DetailsType>
    Details
    Details::merge(
        const Details &another,
        const DetailsType &...others)
    {
        return merge(another).merge(others...);
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
                NTL_MAKE_STATEMENT_INFO("template <typename ReturnType> ReturnType &Details::get_field(const String &name) const"));

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