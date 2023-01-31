#ifndef __NEUTRONTL_MEMORY_BASICDELETER_CPP__
#define __NEUTRONTL_MEMORY_BASICDELETER_CPP__

#include "BasicDeleter.hpp"
#include "../Exception/NullPointerException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_DataType>
    NTL_INLINE void
    BasicDeleter<m_DataType>::operator()(
        BasicDeleter<m_DataType>::DataType *ptr) const
    {
        if (ptr != nullptr)
            delete ptr;
        else
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE void BasicDeleter<m_DataType>::operator()(BasicDeleter<m_DataType>::DataType *ptr) const"));
    }

    template <typename m_DataType>
    NTL_INLINE void
    BasicDeleter<m_DataType[]>::operator()(
        BasicDeleter<m_DataType[]>::DataType *ptr) const
    {
        if (ptr != nullptr)
            delete[] ptr;
        else
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType> NTL_INLINE void BasicDeleter<m_DataType[]>::operator()(BasicDeleter<m_DataType[]>::DataType *ptr) const"));
    }
} // namespace ntl

#endif