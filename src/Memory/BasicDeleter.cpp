#ifndef __NEUTRONTL_MEMORY_BASICDELETER_CPP__
#define __NEUTRONTL_MEMORY_BASICDELETER_CPP__

#include "BasicDeleter.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename m_DataType>
    void BasicDeleter<m_DataType>::operator()(m_DataType *ptr) const
    {
        if (ptr != nullptr)
            delete ptr;
        else
            throw NullPointerException(L"template <typename m_DataType> void BasicDeleter<m_DataType>::operator()(m_DataType *ptr) const");
    }

    template <typename m_DataType>
    void BasicDeleter<m_DataType[]>::operator()(m_DataType *ptr) const
    {
        if (ptr != nullptr)
            delete[] ptr;
        else
            throw NullPointerException(L"template <typename m_DataType[]> void BasicDeleter<m_DataType[]>::operator()(m_DataType *ptr) const");
    }
} // namespace ntl

#endif