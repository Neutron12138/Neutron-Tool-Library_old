#ifndef __NEUTRONTL_MEMORY_POINTER_CPP__
#define __NEUTRONTL_MEMORY_POINTER_CPP__

#include <memory>
#include "Pointer.hpp"
#include "../Exception/NullPointerException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_DataType>
    NTL_INLINE
        typename Pointer<m_DataType>::DataType &
        Pointer<m_DataType>::operator*() const
    {
        if (is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE typename Pointer<m_DataType>::DataType &Pointer<m_DataType>::operator*() const"));
        return *get();
    }

    template <typename m_DataType>
    NTL_INLINE
        typename Pointer<m_DataType>::DataType *
        Pointer<m_DataType>::operator->() const
    {
        if (is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE typename Pointer<m_DataType>::DataType *Pointer<m_DataType>::operator->() const"));
        return get();
    }

    template <typename m_DataType>
    NTL_INLINE bool
    Pointer<m_DataType>::is_nullptr() const
    {
        return get() == nullptr;
    }
} // namespace ntl

#endif