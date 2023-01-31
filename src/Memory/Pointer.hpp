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
        NTL_INLINE NTL_CONSTEXPR Pointer() NTL_NOEXCEPT = default;
        NTL_INLINE NTL_CONSTEXPR Pointer(const SelfType &from) NTL_NOEXCEPT = default;
        NTL_INLINE ~Pointer() NTL_NOEXCEPT = default;

    public:
        NTL_INLINE NTL_CONSTEXPR SelfType &operator=(const SelfType &from) NTL_NOEXCEPT = default;
        virtual NTL_INLINE DataType &operator*() const;
        virtual NTL_INLINE DataType *operator->() const;

    public:
        /// @brief 获取指针
        /// @return 指针
        virtual NTL_INLINE DataType *get() const = 0;

        /// @brief 是否为空指针
        /// @return 是否为空指针
        virtual NTL_INLINE bool is_nullptr() const;
    };
} // namespace ntl

#endif