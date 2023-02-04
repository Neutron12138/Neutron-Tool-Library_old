#ifndef __NEUTRONTL_MEMORY_POINTER_CPP__
#define __NEUTRONTL_MEMORY_POINTER_CPP__

#include <memory>
#include "Pointer.hpp"
#include "../Exception/NullPointerException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    // 普通泛用型

    template <typename m_DataType>
    typename Pointer<m_DataType>::DataType &
    Pointer<m_DataType>::operator*() const
    {
        if (is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE typename Pointer<m_DataType>::DataType &Pointer<m_DataType>::operator*() const"));
        return *get();
    }

    template <typename m_DataType>
    typename Pointer<m_DataType>::DataType *
    Pointer<m_DataType>::operator->() const
    {
        if (is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE typename Pointer<m_DataType>::DataType *Pointer<m_DataType>::operator->() const"));
        return get();
    }

    template <typename m_DataType>
    bool
    Pointer<m_DataType>::is_nullptr() const
    {
        return get() == nullptr;
    }

    // 数组特化型

    template <typename m_DataType>
    typename Pointer<m_DataType[]>::DataType &
    Pointer<m_DataType[]>::operator*() const
    {
        if (is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE typename Pointer<m_DataType>::DataType &Pointer<m_DataType>::operator*() const"));
        return *get();
    }

    template <typename m_DataType>
    typename Pointer<m_DataType[]>::DataType *
    Pointer<m_DataType[]>::operator->() const
    {
        if (is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE typename Pointer<m_DataType>::DataType *Pointer<m_DataType>::operator->() const"));
        return get();
    }

    template <typename m_DataType>
    typename Pointer<m_DataType[]>::DataType &
    Pointer<m_DataType[]>::operator[](SizeT index) const
    {
        if (is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> typename Pointer<m_DataType[]>::DataType *Pointer<m_DataType[]>::operator[](std::size_t index) const"));
        return get()[index];
    }

    template <typename m_DataType>
    bool
    Pointer<m_DataType[]>::is_nullptr() const
    {
        return get() == nullptr;
    }
} // namespace ntl

#endif