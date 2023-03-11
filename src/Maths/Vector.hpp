#ifndef __NEUTRONTL_MATHS_VECTOR_HPP__
#define __NEUTRONTL_MATHS_VECTOR_HPP__

#include <array>
#include <vector>
#include <initializer_list>
#include "../Base/Type.hpp"
#include "../Base/BasicObject.hpp"

namespace ntl
{
    /// @brief 向量
    /// @tparam m_ComponentType 分量类型
    /// @tparam m_dimensions 维数
    template <typename m_ComponentType, SizeT m_dimensions>
    class Vector : public BasicObject
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
        template <SizeT another_dimensions>
        explicit Vector(const std::array<ComponentType, another_dimensions> &another);
        template <typename AllocatorType>
        explicit Vector(const std::vector<ComponentType, AllocatorType> &another);
        explicit Vector(const std::initializer_list<ComponentType> &another);
        template <SizeT another_dimensions>
        explicit Vector(const Vector<ComponentType, another_dimensions> &another);
        explicit Vector(const SelfType &from) = default;
        ~Vector() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        template <SizeT another_dimensions>
        bool operator==(const Vector<ComponentType, another_dimensions> &another);
        

    public:
        static SizeT get_dimensions();
    };

} // namespace ntl

#endif