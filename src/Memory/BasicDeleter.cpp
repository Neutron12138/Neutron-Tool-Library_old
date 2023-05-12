#ifndef __NEUTRONTL_MEMORY_BASICDELETER_CPP__
#define __NEUTRONTL_MEMORY_BASICDELETER_CPP__

#include "BasicDeleter.hpp"
#include "../Exception/NullPointerException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_DataType>
    void
    BasicDeleter<m_DataType>::operator()(
        std::nullptr_t) const
    {
        throw NullPointerException(
            NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> void BasicDeleter<m_DataType>::operator()(std::nullptr_t) const"));
    }

    template <typename m_DataType>
    void
    BasicDeleter<m_DataType>::operator()(
        BasicDeleter<m_DataType>::DataType *ptr) const
    {
        if (ptr != nullptr)
            delete ptr;
        else
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> void BasicDeleter<m_DataType>::operator()(BasicDeleter<m_DataType>::DataType *ptr) const"));
    }

    template <typename m_DataType>
    void
    BasicDeleter<m_DataType>::operator()(
        void *ptr) const
    {
        if (ptr != nullptr)
            operator()(reinterpret_cast<DataType *>(ptr));
        else
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> void BasicDeleter<m_DataType>::operator()(void *ptr) const"));
    }

    //
    // 数组特化
    //

    template <typename m_DataType>
    void
    BasicDeleter<m_DataType[]>::operator()(
        std::nullptr_t) const
    {
        throw NullPointerException(
            NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> void BasicDeleter<m_DataType[]>::operator()(std::nullptr_t) const"));
    }

    template <typename m_DataType>
    void
    BasicDeleter<m_DataType[]>::operator()(
        BasicDeleter<m_DataType[]>::DataType *ptr) const
    {
        if (ptr != nullptr)
            delete[] ptr;
        else
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> void BasicDeleter<m_DataType[]>::operator()(BasicDeleter<m_DataType[]>::DataType *ptr) const"));
    }

    template <typename m_DataType>
    void
    BasicDeleter<m_DataType[]>::operator()(
        void *ptr) const
    {
        if (ptr != nullptr)
            operator()(reinterpret_cast<DataType *>(ptr));
        else
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> void BasicDeleter<m_DataType[]>::operator()(BasicDeleter<m_DataType[]>::DataType *ptr) const"));
    }

} // namespace ntl

#endif
