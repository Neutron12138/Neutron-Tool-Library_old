#ifndef __NEUTRONTL_MEMORY_WEAKPOINTER_CPP__
#define __NEUTRONTL_MEMORY_WEAKPOINTER_CPP__

#include "WeakPointer.hpp"

namespace ntl
{
    template <typename m_DataType>
    WeakPointer<m_DataType>::WeakPointer(
        const typename WeakPointer<m_DataType>::SharedPointerType &ptr)
        : WeakPointer<m_DataType>::ParentType(ptr) {}

    template <typename m_DataType>
    typename WeakPointer<m_DataType>::SelfType &
    WeakPointer<m_DataType>::operator=(
        const typename WeakPointer<m_DataType>::SharedPointerType &ptr)
    {
        WeakPointer<m_DataType>::ParentType::operator=(ptr);
        return *this;
    }
} // namespace ntl

#endif