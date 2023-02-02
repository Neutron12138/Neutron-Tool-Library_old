#ifndef __NEUTRONTL_MEMORY_POINTER_HPP__
#define __NEUTRONTL_MEMORY_POINTER_HPP__

#include "../Base/Object.hpp"

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
        NTL_CONSTEXPR Pointer() NTL_NOEXCEPT = default;
        NTL_CONSTEXPR NTL_EXPLICIT Pointer(const SelfType &from) NTL_NOEXCEPT = default;
        ~Pointer() NTL_OVERRIDE = default;

    public:
        NTL_INLINE NTL_CONSTEXPR SelfType &operator=(const SelfType &from) NTL_NOEXCEPT = default;
        NTL_VIRTUAL DataType &operator*() const;
        NTL_VIRTUAL DataType *operator->() const;

    public:
        /// @brief 获取指针
        /// @return 指针
        NTL_VIRTUAL DataType *get() const = 0;

        /// @brief 是否为空指针
        /// @return 是否为空指针
        NTL_VIRTUAL bool is_nullptr() const;
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
        NTL_CONSTEXPR Pointer() NTL_NOEXCEPT = default;
        NTL_CONSTEXPR NTL_EXPLICIT Pointer(const SelfType &from) NTL_NOEXCEPT = default;
        ~Pointer() NTL_OVERRIDE = default;

    public:
        NTL_INLINE NTL_CONSTEXPR SelfType &operator=(const SelfType &from) NTL_NOEXCEPT = default;
        NTL_VIRTUAL DataType &operator*() const;
        NTL_VIRTUAL DataType *operator->() const;
        NTL_VIRTUAL DataType &operator[](std::size_t index) const;

    public:
        /// @brief 获取指针
        /// @return 指针
        NTL_VIRTUAL DataType *get() const = 0;

        /// @brief 是否为空指针
        /// @return 是否为空指针
        NTL_VIRTUAL bool is_nullptr() const;
    };
} // namespace ntl

#endif