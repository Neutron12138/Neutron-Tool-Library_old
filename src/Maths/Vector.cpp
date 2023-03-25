#ifndef __NEUTRONTL_MATHS_VECTOR_CPP__
#define __NEUTRONTL_MATHS_VECTOR_CPP__

#include <cmath>
#include "Vector.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_ComponentType, SizeT m_dimensions>
    Vector<m_ComponentType, m_dimensions>::Vector(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentHolder &components)
        : m_components(components) {}

    template <typename m_ComponentType, SizeT m_dimensions>
    bool
    Vector<m_ComponentType, m_dimensions>::operator==(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        for (SizeT i = 0; i < m_dimensions; i++)
            if (m_components.at(i) != another.m_components.at(i))
                return false;
        return true;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    bool
    Vector<m_ComponentType, m_dimensions>::operator!=(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        return !operator==(another);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::ComponentType &
    Vector<m_ComponentType, m_dimensions>::operator[](
        SizeT index)
    {
        try
        {
            ComponentType &result =
                m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ComponentType, SizeT m_dimensions> typename Vector<m_ComponentType, m_dimensions>::ComponentType &Vector<m_ComponentType, m_dimensions>::operator[](SizeT index)"));
        }
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    const typename Vector<m_ComponentType, m_dimensions>::ComponentType &
    Vector<m_ComponentType, m_dimensions>::operator[](
        SizeT index) const
    {
        try
        {
            const ComponentType &result =
                m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ComponentType, SizeT m_dimensions> const typename Vector<m_ComponentType, m_dimensions>::ComponentType &Vector<m_ComponentType, m_dimensions>::operator[](SizeT index) const"));
        }
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator-() const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element) -> void
                        { element = -element; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator+(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const SelfType &another) -> void
                        { element = element + another[index]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator-(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const SelfType &another) -> void
                        { element = element - another[index]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator*(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const SelfType &another) -> void
                        { element = element * another[index]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator/(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const SelfType &another) -> void
                        { element = element / another[index]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator%(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const SelfType &another) -> void
                        { element = element % another[index]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator*(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const ComponentType &another) -> void
                        { element = element * another; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator/(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const ComponentType &another) -> void
                        { element = element / another; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::operator%(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT index, ComponentType &element, const ComponentType &another) -> void
                        { element = element % another; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator+=(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another)
    {
        *this = *this + another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator-=(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another)
    {
        *this = *this - another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator*=(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another)
    {
        *this = *this * another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator/=(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another)
    {
        *this = *this / another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator%=(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another)
    {
        *this = *this % another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator*=(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentType &another)
    {
        *this = *this * another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator/=(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentType &another)
    {
        *this = *this / another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::operator%=(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentType &another)
    {
        *this = *this % another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    const typename Vector<m_ComponentType, m_dimensions>::ComponentHolder &
    Vector<m_ComponentType, m_dimensions>::get_components() const
    {
        return m_components;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::set_components(
        const typename Vector<m_ComponentType, m_dimensions>::ComponentHolder &components)
    {
        m_components = components;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::swap(
        typename Vector<m_ComponentType, m_dimensions>::SelfType &another)
    {
        m_components.swap(another.m_components);
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    template <typename FuncType, typename... ArgsType>
    void
    Vector<m_ComponentType, m_dimensions>::for_each(
        FuncType func,
        ArgsType &&...args)
    {
        for (SizeT i = 0; i < m_dimensions; i++)
            func(
                i,
                m_components.at(i),
                std::forward<ArgsType>(args)...);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    template <typename FuncType, typename... ArgsType>
    void
    Vector<m_ComponentType, m_dimensions>::for_each(
        FuncType func,
        ArgsType &&...args) const
    {
        for (SizeT i = 0; i < m_dimensions; i++)
            func(
                i,
                m_components.at(i),
                std::forward<ArgsType>(args)...);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::ComponentType
    Vector<m_ComponentType, m_dimensions>::dot(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &another) const
    {
        typename Vector<m_ComponentType, m_dimensions>::ComponentType result = 0;

        for (SizeT i = 0; i < m_dimensions; i++)
            result += m_components.at(i) * another.m_components.at(i);

        return result;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::reflect(
        const typename Vector<m_ComponentType, m_dimensions>::SelfType &normal) const
    {
        return *this - 2.0f * dot(normal) * normal;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::ComponentType
    Vector<m_ComponentType, m_dimensions>::length() const
    {
        return std::sqrt(dot(*this));
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType &
    Vector<m_ComponentType, m_dimensions>::normalize()
    {
        *this = normalized();
        return *this;
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    typename Vector<m_ComponentType, m_dimensions>::SelfType
    Vector<m_ComponentType, m_dimensions>::normalized() const
    {
        using SelfType = Vector<m_ComponentType, m_dimensions>::SelfType;

        SelfType result = SelfType(*this);

        const typename SelfType::ComponentType len =
            result.length();

        for (SizeT i = 0; i < m_dimensions; i++)
            result.m_components.at(i) /= len;

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_dimensions>
    SizeT
    Vector<m_ComponentType, m_dimensions>::get_dimensions()
    {
        return m_dimensions;
    }

    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions>
    operator*(
        const ComponentType &value,
        const Vector<ComponentType, dimensions> &vector)
    {
        return vector * value;
    }

    template <typename ComponentType>
    Vector<ComponentType, 2> make_vector(
        const ComponentType &comp0,
        const ComponentType &comp1)
    {
        return Vector<ComponentType, 2>(
            std::array<ComponentType, 2>(
                {
                    comp0,
                    comp1,
                }));
    }

    template <typename ComponentType>
    Vector<ComponentType, 3> make_vector(
        const ComponentType &comp0,
        const ComponentType &comp1,
        const ComponentType &comp2)
    {
        return Vector<ComponentType, 3>(
            std::array<ComponentType, 3>(
                {
                    comp0,
                    comp1,
                    comp2,
                }));
    }

    template <typename ComponentType>
    Vector<ComponentType, 4> make_vector(
        const ComponentType &comp0,
        const ComponentType &comp1,
        const ComponentType &comp2,
        const ComponentType &comp3)
    {
        return Vector<ComponentType, 4>(
            std::array<ComponentType, 4>(
                {
                    comp0,
                    comp1,
                    comp2,
                    comp3,
                }));
    }

} // namespace ntl

#endif