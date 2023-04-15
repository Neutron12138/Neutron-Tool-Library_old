#ifndef __NEUTRONTL_MATHS_VECTOR_HPP__
#define __NEUTRONTL_MATHS_VECTOR_HPP__

#include <array>
#include <vector>
#include <initializer_list>
#include "../Base/Type.hpp"
#include "../Base/BasicObject.hpp"
#include "Angle.hpp"

namespace ntl
{
    /// @brief 向量
    /// @tparam m_ComponentType 分量类型
    /// @tparam m_dimensions 维数
    template <typename m_ComponentType, SizeT m_dimensions>
    class NTL_ALIGN Vector : public BasicObject
    {
    public:
        /// @brief 分量类型
        using ComponentType = m_ComponentType;

        /// @brief 分量持有者
        using ComponentHolder = std::array<ComponentType, m_dimensions>;

        using SelfType = Vector<ComponentType, m_dimensions>;
        using ParentType = BasicObject;

    protected:
        /// @brief 分量
        ComponentHolder m_components;

    public:
        Vector() = default;
        explicit Vector(const ComponentHolder &components);
        explicit Vector(const SelfType &from) = default;
        ~Vector() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

        bool operator==(const SelfType &another) const;
        bool operator!=(const SelfType &another) const;

        ComponentType &operator[](SizeT index);
        const ComponentType &operator[](SizeT index) const;

        SelfType operator-() const;
        SelfType operator+(const SelfType &another) const;
        SelfType operator-(const SelfType &another) const;
        SelfType operator*(const SelfType &another) const;
        SelfType operator/(const SelfType &another) const;
        SelfType operator%(const SelfType &another) const;
        SelfType operator+(const ComponentType &another) const;
        SelfType operator-(const ComponentType &another) const;
        SelfType operator*(const ComponentType &another) const;
        SelfType operator/(const ComponentType &another) const;
        SelfType operator%(const ComponentType &another) const;

        SelfType &operator+=(const SelfType &another);
        SelfType &operator-=(const SelfType &another);
        SelfType &operator*=(const SelfType &another);
        SelfType &operator/=(const SelfType &another);
        SelfType &operator%=(const SelfType &another);
        SelfType &operator+=(const ComponentType &another);
        SelfType &operator-=(const ComponentType &another);
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
        /// @brief 获取与另一向量的点乘
        /// @param another 另一个向量
        /// @return 点乘结果
        ComponentType dot(const SelfType &another) const;

        /// @brief 将本向量沿法向量反射
        /// @param normal 法向量
        /// @return 反射后的向量
        SelfType reflect(const SelfType &normal) const;

        /// @brief 计算与另一向量之间的夹角
        /// @param another 另一个向量
        /// @return 与另一向量之间的夹角
        Angle<ComponentType> included_angle_with(const SelfType &another) const;

    public:
        /// @brief 获取向量的模（module），但是与C++20关键字相冲突
        /// @return 向量的模（长度）
        ComponentType length() const;

        /// @brief 规范化本向量
        /// @return 本对象
        SelfType &normalize();

        /// @brief 规范化后的本向量
        /// @return 本向量的单位向量
        SelfType normalized() const;

        /// @brief 判断本向量是否为单位向量，由于精度问题，不一定对
        /// @return 本向量是否为单位向量
        bool is_normalized() const;

    public:
        /// @brief 获取本向量的维数
        /// @return 本向量的维数
        static SizeT get_dimensions();
    };

    //
    // 运算符重载函数
    //

    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions> operator+(
        const ComponentType &value,
        const Vector<ComponentType, dimensions> &vector);
    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions> operator-(
        const ComponentType &value,
        const Vector<ComponentType, dimensions> &vector);
    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions> operator*(
        const ComponentType &value,
        const Vector<ComponentType, dimensions> &vector);
    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions> operator/(
        const ComponentType &value,
        const Vector<ComponentType, dimensions> &vector);
    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions> operator%(
        const ComponentType &value,
        const Vector<ComponentType, dimensions> &vector);

    //
    // 工具函数
    //

    template<typename ComponentType,SizeT dimensions,SizeT size>
    Vector<ComponentType,dimensions> make_vector(const Vector<ComponentType,size>&another);

    template <typename ComponentType, SizeT dimensions,SizeT size>
    Vector<ComponentType, dimensions> make_vector(std::array<ComponentType,size> &components);
    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions> make_vector(std::vector<ComponentType> &components);
    template <typename ComponentType, SizeT dimensions>
    Vector<ComponentType, dimensions> make_vector(std::initializer_list<ComponentType> &components);

    template <typename ComponentType>
    Vector<ComponentType, 2> make_vector(
        const ComponentType &comp0,
        const ComponentType &comp1);
    template <typename ComponentType>
    Vector<ComponentType, 3> make_vector(
        const ComponentType &comp0,
        const ComponentType &comp1,
        const ComponentType &comp2);
    template <typename ComponentType>
    Vector<ComponentType, 4> make_vector(
        const ComponentType &comp0,
        const ComponentType &comp1,
        const ComponentType &comp2,
        const ComponentType &comp3);

} // namespace ntl

#endif
