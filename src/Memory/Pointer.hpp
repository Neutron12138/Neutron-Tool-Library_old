#ifndef __NEUTRONTL_MEMORY_POINTER_HPP__
#define __NEUTRONTL_MEMORY_POINTER_HPP__

#include "../Base/Object.hpp"
#include "../Base/Type.hpp"

namespace ntl
{
    /// @brief 基础指针类型
    /// @tparam m_DataType 数据类型
    template <typename m_DataType>
    class NTL_ALIGN Pointer : public Object
    {
    public:
        using DataType = m_DataType;
        using SelfType = Pointer<DataType>;
        using ParentType = Object;

    public:
        constexpr Pointer() noexcept = default;
        constexpr Pointer(const SelfType &from) noexcept = default;
        ~Pointer() override = default;

    public:
        inline constexpr SelfType &operator=(const SelfType &from) noexcept = default;
        virtual DataType &operator*() const;
        virtual DataType *operator->() const;

    public:
        /// @brief 获取指针
        /// @return 指针
        virtual DataType *get() const = 0;

        /// @brief 是否为空指针
        /// @return 是否为空指针
        virtual bool is_nullptr() const;
    };

    /// @brief 基础指针类型，数组特化型
    /// @tparam m_DataType 数据类型
    template <typename m_DataType>
    class NTL_ALIGN Pointer<m_DataType[]> : public Object
    {
    public:
        using DataType = m_DataType;
        using SelfType = Pointer<DataType[]>;
        using ParentType = Object;

    public:
        constexpr Pointer() noexcept = default;
        constexpr Pointer(const SelfType &from) noexcept = default;
        ~Pointer() override = default;

    public:
        inline constexpr SelfType &operator=(const SelfType &from) noexcept = default;
        virtual DataType &operator*() const;
        virtual DataType *operator->() const;
        virtual DataType &operator[](SizeT index) const;

    public:
        /// @brief 获取指针
        /// @return 指针
        virtual DataType *get() const = 0;

        /// @brief 是否为空指针
        /// @return 是否为空指针
        virtual bool is_nullptr() const;
    };
} // namespace ntl

#endif