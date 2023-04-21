#ifndef __NEUTRONTL_MATHS_MATRIX_CPP__
#define __NEUTRONTL_MATHS_MATRIX_CPP__

#include "Matrix.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"
#include "Numbers.hpp"

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

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element + another[i][j]; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator-(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element - another[i][j]; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator*(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element * another[i][j]; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator/(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element / another[i][j]; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator%(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element % another[i][j]; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator+(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element + another; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator-(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element - another; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator*(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element * another; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator/(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element / another; });

        return SelfType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    typename Matrix<m_ComponentType, m_rows, m_columns>::SelfType
    Matrix<m_ComponentType, m_rows, m_columns>::operator%(
        const typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType &another) const
    {
        SelfType result = SelfType(*this);

        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = element % another; });

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
    Vector<typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType, m_rows>
    Matrix<m_ComponentType, m_rows, m_columns>::multiply(
        const Vector<m_ComponentType, m_columns> &another) const
    {
        using VectorType = Vector<typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType, m_rows>;

        VectorType result;
        result.for_each([another](SizeT i, ComponentType &element) -> void
                        {
                            element = Numbers::Zero();
                            for(SizeT j = 0;j < m_columns;j++)
                            {
                                element += operator[](i)[j] * another[j];
                            } });

        return VectorType(result);
    }

    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    template <SizeT columns>
    Matrix<typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType, m_rows, columns>
    Matrix<m_ComponentType, m_rows, m_columns>::multiply(
        const Matrix<typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType, m_columns, columns> &another) const
    {
        using MatrixType = Matrix<typename Matrix<m_ComponentType, m_rows, m_columns>::ComponentType, m_rows, columns>;

        MatrixType result;
        result.for_each([another](SizeT i, SizeT j, ComponentType &element) -> void
                        { 
                            element = Numbers::Zero();
                            for(SizeT k = 0;k < m_columns;k++)
                            {
                                element += operator[](i)[k] * another[k][j];
                            } });

        return MatrixType(result);
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
    operator+(
        const ComponentType &value,
        const Matrix<ComponentType, rows, columns> &matrix)
    {
        using MatrixType = Matrix<ComponentType, rows, columns>;

        MatrixType result = MatrixType(matrix);
        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = value + element; });

        return MatrixType(result);
    }

    template <typename ComponentType, SizeT rows, SizeT columns>
    Matrix<ComponentType, rows, columns>
    operator-(
        const ComponentType &value,
        const Matrix<ComponentType, rows, columns> &matrix)
    {
        using MatrixType = Matrix<ComponentType, rows, columns>;

        MatrixType result = MatrixType(matrix);
        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = value - element; });

        return MatrixType(result);
    }

    template <typename ComponentType, SizeT rows, SizeT columns>
    Matrix<ComponentType, rows, columns>
    operator*(
        const ComponentType &value,
        const Matrix<ComponentType, rows, columns> &matrix)
    {
        using MatrixType = Matrix<ComponentType, rows, columns>;

        MatrixType result = MatrixType(matrix);
        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = value * element; });

        return MatrixType(result);
    }

    template <typename ComponentType, SizeT rows, SizeT columns>
    Matrix<ComponentType, rows, columns>
    operator/(
        const ComponentType &value,
        const Matrix<ComponentType, rows, columns> &matrix)
    {
        using MatrixType = Matrix<ComponentType, rows, columns>;

        MatrixType result = MatrixType(matrix);
        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = value / element; });

        return MatrixType(result);
    }

    template <typename ComponentType, SizeT rows, SizeT columns>
    Matrix<ComponentType, rows, columns>
    operator%(
        const ComponentType &value,
        const Matrix<ComponentType, rows, columns> &matrix)
    {
        using MatrixType = Matrix<ComponentType, rows, columns>;

        MatrixType result = MatrixType(matrix);
        result.for_each([=](SizeT i, SizeT j, ComponentType &element) -> void
                        { element = value % element; });

        return MatrixType(result);
    }

    template <typename ComponentType>
    Matrix<ComponentType, 2, 2>
    make_identity_matrix2()
    {
        return make_matrix(
            make_vector<ComponentType>(
                Numbers::One(), Numbers::Zero()),
            make_vector<ComponentType>(
                Numbers::Zero(), Numbers::One()));
    }

    template <typename ComponentType>
    Matrix<ComponentType, 3, 3>
    make_identity_matrix3()
    {
        return make_matrix(
            make_vector<ComponentType>(
                Numbers::One(), Numbers::Zero(), Numbers::Zero()),
            make_vector<ComponentType>(
                Numbers::Zero(), Numbers::One(), Numbers::Zero()),
            make_vector<ComponentType>(
                Numbers::Zero(), Numbers::Zero(), Numbers::One()));
    }

    template <typename ComponentType>
    Matrix<ComponentType, 4, 4>
    make_identity_matrix4()
    {
        return make_matrix(
            make_vector<ComponentType>(
                Numbers::One(), Numbers::Zero(), Numbers::Zero(), Numbers::Zero()),
            make_vector<ComponentType>(
                Numbers::Zero(), Numbers::One(), Numbers::Zero(), Numbers::Zero()),
            make_vector<ComponentType>(
                Numbers::Zero(), Numbers::Zero(), Numbers::One(), Numbers::Zero()),
            make_vector<ComponentType>(
                Numbers::Zero(), Numbers::Zero(), Numbers::Zero(), Numbers::One()));
    }

    template <typename ComponentType>
    Matrix<ComponentType, 2, 2>
    make_matrix(
        const Vector<ComponentType, 2> &row0,
        const Vector<ComponentType, 2> &row1)
    {
        using VectorType = Vector<ComponentType, 2>;
        return Matrix<ComponentType, 2, 2>(
            typename Matrix<ComponentType, 2, 2>::ComponentHolder(
                {
                    VectorType(row0),
                    VectorType(row1),
                }));
    }

    template <typename ComponentType>
    Matrix<ComponentType, 3, 3>
    make_matrix(
        const Vector<ComponentType, 3> &row0,
        const Vector<ComponentType, 3> &row1,
        const Vector<ComponentType, 3> &row2)
    {
        using VectorType = Vector<ComponentType, 3>;
        return Matrix<ComponentType, 3, 3>(
            typename Matrix<ComponentType, 3, 3>::ComponentHolder(
                {
                    VectorType(row0),
                    VectorType(row1),
                    VectorType(row2),
                }));
    }

    template <typename ComponentType>
    Matrix<ComponentType, 4, 4>
    make_matrix(
        const Vector<ComponentType, 4> &row0,
        const Vector<ComponentType, 4> &row1,
        const Vector<ComponentType, 4> &row2,
        const Vector<ComponentType, 4> &row3)
    {
        using VectorType = Vector<ComponentType, 4>;
        return Matrix<ComponentType, 4, 4>(
            typename Matrix<ComponentType, 4, 4>::ComponentHolder(
                {
                    VectorType(row0),
                    VectorType(row1),
                    VectorType(row2),
                    VectorType(row3),
                }));
    }

} // namespace ntl

#endif
