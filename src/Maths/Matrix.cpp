#ifndef __NEUTRONTL_MATHS_MATRIX_CPP__
#define __NEUTRONTL_MATHS_MATRIX_CPP__

#include "Matrix.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    Matrix<m_ComponentType, m_rows, m_columns>::Matrix(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentHolder &components)
        : m_components(components) {}

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    bool
    Matrix<m_ComponentType, m_rows, m_columns>::operator==(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        for (SizeT i = 0; i < m_rows; i++)
            if (m_components.at(i) != another.m_components.at(i))
                return false;
        return true;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    bool
    Matrix<m_ComponentType, m_rows, m_columns>::operator!=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        return !operator=(another);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::RowType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator[](
        SizeT index)
    {
        try
        {
            RowType &result = m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ComponentType, SizeT m_rows, SizeT m_columns> typename Matrix<m_ComponentType, m_rows, m_columns>::RowType &Matrix<m_ComponentType, m_rows, m_columns>::operator[](SizeT index)"));
        }
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    const typename Matrix<m_ComponentType, m_rows, m_columns>::RowType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator[](
        SizeT index) const
    {
        try
        {
            const RowType &result = m_components.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ComponentType, SizeT m_rows, SizeT m_columns> const typename Matrix<m_ComponentType, m_rows, m_columns>::RowType &Matrix<m_ComponentType, m_rows, m_columns>::operator[](SizeT index) const"));
        }
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator-() const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = -element; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator+(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const SelfType &another) -> void
                        { element = element + another[i][j]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator-(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const SelfType &another) -> void
                        { element = element - another[i][j]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator*(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const SelfType &another) -> void
                        { element = element * another[i][j]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator/(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const SelfType &another) -> void
                        { element = element / another[i][j]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator%(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const SelfType &another) -> void
                        { element = element % another[i][j]; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator*(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const ComponentType &another) -> void
                        { element = element * another; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator/(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const ComponentType &another) -> void
                        { element = element / another; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator%(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([](SizeT i, SizeT j, ComponentType &element, const ComponentType &another) -> void
                        { element = element % another; },
                        another);

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator+=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another)
    {
        *this = *this + another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator-=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another)
    {
        *this = *this - another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator*=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another)
    {
        *this = *this * another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator/=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another)
    {
        *this = *this / another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator%=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another)
    {
        *this = *this % another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator*=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another)
    {
        *this = *this * another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator/=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another)
    {
        *this = *this / another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::operator%=(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another)
    {
        *this = *this % another;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentHolder &
    Matrix<m_ComponentType, m_rows, m_columns>::get_components() const
    {
        return m_components;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::set_components(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentHolder &components)
    {
        m_components = components;
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &
    Matrix<m_ComponentType, m_rows, m_columns>::swap(
        typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another)
    {
        m_components.swap(another.m_components);
        return *this;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    template <typename FuncType, typename... ArgsType>
    void
    Matrix<m_ComponentType, m_rows, m_columns>::for_each(
        FuncType func,
        ArgsType &&...args)
    {
        for (SizeT i = 0; i < m_rows; i++)
            for (SizeT j = 0; j < m_columns; j++)
                func(
                    i,
                    j,
                    m_components.at(i)[j],
                    std::forward<ArgsType>(args)...);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    template <typename FuncType, typename... ArgsType>
    void
    Matrix<m_ComponentType, m_rows, m_columns>::for_each(
        FuncType func,
        ArgsType &&...args) const
    {
        for (SizeT i = 0; i < m_rows; i++)
            for (SizeT j = 0; j < m_columns; j++)
                func(
                    i,
                    j,
                    m_components.at(i)[j],
                    std::forward<ArgsType>(args)...);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    SizeT
    Matrix<m_ComponentType, m_rows, m_columns>::get_rows()
    {
        return m_rows;
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    SizeT
    Matrix<m_ComponentType, m_rows, m_columns>::get_columns()
    {
        return m_columns;
    }

    template <typename ComponentType, SizeT rows, SizeT columns>
    Matrix<ComponentType, rows, columns>
    operator*(
        const ComponentType &value,
        const Matrix<ComponentType, rows, columns> &matrix)
    {
        return matrix * value;
    }

} // namespace ntl

#endif
