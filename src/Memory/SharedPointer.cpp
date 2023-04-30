#ifndef __NEUTRONTL_MEMORY_SHAREDPOINTER_CPP__
#define __NEUTRONTL_MEMORY_SHAREDPOINTER_CPP__

#include "SharedPointer.hpp"
#include "../Exception/NullPointerException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_DataType>
    template <typename DataType2>
    SharedPointer<m_DataType>::SharedPointer(
        DataType2 *ptr)
        : SharedPointer<m_DataType>::ParentType(ptr) {}

    template <typename m_DataType>
    template <typename DataType2, typename DeleterType>
    SharedPointer<m_DataType>::SharedPointer(
        DataType2 *ptr,
        DeleterType deleter)
        : SharedPointer<m_DataType>::ParentType(ptr, deleter) {}

    template <typename m_DataType>
    typename SharedPointer<m_DataType>::DataType &
    SharedPointer<m_DataType>::operator*() const
    {
        if (Pointer<m_DataType>::is_nullptr())
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> NTL_INLINE typename SharedPointer<m_DataType>::DataType &SharedPointer<m_DataType>::operator*() const"));
        return *get();
    }

    template <typename m_DataType>
    typename SharedPointer<m_DataType>::DataType *
    SharedPointer<m_DataType>::operator->() const
    {
        if (Pointer<m_DataType>::is_nullptr())
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_DataType> NTL_INLINE typename SharedPointer<m_DataType>::DataType *SharedPointer<m_DataType>::operator->() const"));
        return get();
    }

    template <typename m_DataType>
    typename SharedPointer<m_DataType>::DataType *
    SharedPointer<m_DataType>::get() const
    {
        return SharedPointer<m_DataType>::ParentType::get();
    }

    template <typename DataType, typename... ArgsType>
    SharedPointer<DataType>
    make_shared(
        ArgsType &&...args)
    {
        return SharedPointer<DataType>(
            new DataType(
                std::forward<ArgsType>(args)...));
    }

    template <typename DataType, typename DeleterType, typename... ArgsType>
    SharedPointer<DataType>
    make_shared_and_deleter(
        DeleterType deleter,
        ArgsType &&...args)
    {
        return SharedPointer<DataType>(
            new DataType(
                std::forward<ArgsType>(args)...),
            DeleterType(deleter));
    }

} // namespace ntl

#endif