#ifndef __NEUTRONTL_MATHS_MATRIX_HPP__
#define __NEUTRONTL_MATHS_MATRIX_HPP__

#include <array>
#include "../Base/BasicObject.hpp"
#include "Vector.hpp"

namespace ntl
{
    /// @brief 矩阵
    /// @tparam m_ComponentType 分量类型
    /// @tparam m_rows 行
    /// @tparam m_columns 列
    template <typename m_ComponentType, SizeT m_rows, SizeT m_columns>
    class Matrix : public BasicObject
    {
    public:
        using ComponentType = m_ComponentType;
        using RowType = Vector<ComponentType, m_columns>;
        using ColumnType = Vector<ComponentType, m_rows>;

        using SelfType = Matrix<ComponentType, m_rows, m_columns>;
        using ParentType = BasicObject;

        using ComponentHolder = std::array<RowType, m_rows>;

    protected:
        /// @brief 分量
        ComponentHolder m_components;

    public:
        Matrix() = default;
        explicit Matrix(const ComponentHolder &components);
        explicit Matrix(const SelfType &from) = default;
        ~Matrix() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

        bool operator==(const SelfType &another) const;
        bool operator!=(const SelfType &another) const;

        RowType &operator[](SizeT index);
        const RowType &operator[](SizeT index) const;

        SelfType operator-() const;
        SelfType operator+(const SelfType &another) const;
        SelfType operator-(const SelfType &another) const;
        SelfType operator*(const SelfType &another) const;
        SelfType operator/(const SelfType &another) const;
        SelfType operator%(const SelfType &another) const;
        SelfType operator*(const ComponentType &another) const;
        SelfType operator/(const ComponentType &another) const;
        SelfType operator%(const ComponentType &another) const;

        SelfType &operator+=(const SelfType &another);
        SelfType &operator-=(const SelfType &another);
        SelfType &operator*=(const SelfType &another);
        SelfType &operator/=(const SelfType &another);
        SelfType &operator%=(const SelfType &another);
        SelfType &operator*=(const ComponentType &another);
        SelfType &operator/=(const ComponentType &another);
        SelfType &operator%=(const ComponentType &another);

    public:
        const ComponentHolder &get_components() const;
        SelfType &set_components(const ComponentHolder &components);
        SelfType &swap(SelfType &another);

        template <typename FuncType, typename... ArgsType>
        void for_each(FuncType func, ArgsType &&...args);
        template <typename FuncType, typename... ArgsType>
        void for_each(FuncType func, ArgsType &&...args) const;

    public:
        static SizeT get_rows();
        static SizeT get_columns();
    };

    template <typename ComponentType, SizeT rows, SizeT columns>
    Matrix<ComponentType, rows, columns> operator*(
        const ComponentType &value,
        const Matrix<ComponentType, rows, columns> &matrix);

    template <typename ComponentType>
    using Matrix2x2 = Matrix<ComponentType, 2, 2>;
    template <typename ComponentType>
    using Matrix2x3 = Matrix<ComponentType, 2, 3>;
    template <typename ComponentType>
    using Matrix2x4 = Matrix<ComponentType, 2, 4>;

    template <typename ComponentType>
    using Matrix3x2 = Matrix<ComponentType, 3, 2>;
    template <typename ComponentType>
    using Matrix3x3 = Matrix<ComponentType, 3, 3>;
    template <typename ComponentType>
    using Matrix3x4 = Matrix<ComponentType, 3, 4>;

    template <typename ComponentType>
    using Matrix4x2 = Matrix<ComponentType, 4, 2>;
    template <typename ComponentType>
    using Matrix4x3 = Matrix<ComponentType, 4, 3>;
    template <typename ComponentType>
    using Matrix4x4 = Matrix<ComponentType, 4, 4>;

    template <typename ComponentType>
    using Matrix2 = Matrix2x2<ComponentType>;
    template <typename ComponentType>
    using Matrix3 = Matrix3x3<ComponentType>;
    template <typename ComponentType>
    using Matrix4 = Matrix4x4<ComponentType>;

} // namespace ntl

#endif