#ifndef __NEUTRONTL_MEMORY_UNIQUEPOINTER_CPP__
#define __NEUTRONTL_MEMORY_UNIQUEPOINTER_CPP__

#include "UniquePointer.hpp"
#include "../Exception/NullPointerException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_DataType, typename m_DeleterType>
    UniquePointer<m_DataType, m_DeleterType>::UniquePointer(
        typename UniquePointer<m_DataType, m_DeleterType>::UniquePointer::DataType *ptr)
        : UniquePointer<m_DataType, m_DeleterType>::ParentType(ptr) {}

    template <typename m_DataType, typename m_DeleterType>
    UniquePointer<m_DataType, m_DeleterType>::UniquePointer(
        typename UniquePointer<m_DataType, m_DeleterType>::UniquePointer::DataType *ptr,
        typename UniquePointer<m_DataType, m_DeleterType>::UniquePointer::DeleterType deleter)
        : UniquePointer<m_DataType, m_DeleterType>::ParentType(ptr, deleter) {}

    template <typename m_DataType, typename m_DeleterType>
    UniquePointer<m_DataType, m_DeleterType>::UniquePointer(
        typename UniquePointer<m_DataType, m_DeleterType>::SelfType &&from)
        : UniquePointer<m_DataType, m_DeleterType>::ParentType(std::move(from)) {}

    template <typename m_DataType, typename m_DeleterType>
    typename UniquePointer<m_DataType, m_DeleterType>::SelfType &
    UniquePointer<m_DataType, m_DeleterType>::operator=(
        typename UniquePointer<m_DataType, m_DeleterType>::SelfType &&from)
    {
        UniquePointer<m_DataType, m_DeleterType>::ParentType::operator=(std::move(from));
        return *this;
    }

    template <typename m_DataType, typename m_DeleterType>
    NTL_INLINE
        typename UniquePointer<m_DataType, m_DeleterType>::DataType &
        UniquePointer<m_DataType, m_DeleterType>::operator*() const
    {
        if (Pointer<m_DataType>::is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType, typename m_DeleterType> NTL_INLINE typename UniquePointer<m_DataType, m_DeleterType>::DataType &UniquePointer<m_DataType, m_DeleterType>::operator*() const"));
        return *get();
    }

    template <typename m_DataType, typename m_DeleterType>
    NTL_INLINE
        typename UniquePointer<m_DataType, m_DeleterType>::DataType *
        UniquePointer<m_DataType, m_DeleterType>::operator->() const
    {
        if (Pointer<m_DataType>::is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType, typename m_DeleterType> NTL_INLINE typename UniquePointer<m_DataType, m_DeleterType>::DataType *UniquePointer<m_DataType, m_DeleterType>::operator->() const"));
        return get();
    }

    template <typename m_DataType, typename m_DeleterType>
    typename UniquePointer<m_DataType, m_DeleterType>::DataType *
    UniquePointer<m_DataType, m_DeleterType>::get() const
    {
        return UniquePointer<m_DataType, m_DeleterType>::ParentType::get();
    }

    template <typename m_DataType, typename m_DeleterType>
    UniquePointer<m_DataType[], m_DeleterType>::UniquePointer(
        DataType *ptr)
        : UniquePointer<m_DataType[], m_DeleterType>::ParentType(ptr) {}

    template <typename m_DataType, typename m_DeleterType>
    UniquePointer<m_DataType[], m_DeleterType>::UniquePointer(DataType *ptr,
                                                              DeleterType deleter)
        : UniquePointer<m_DataType[], m_DeleterType>::ParentType(ptr, deleter) {}

    template <typename m_DataType, typename m_DeleterType>
    UniquePointer<m_DataType[], m_DeleterType>::UniquePointer(
        typename UniquePointer<m_DataType[], m_DeleterType>::SelfType &&from)
        : UniquePointer<m_DataType[], m_DeleterType>::ParentType()
    {
        *this = std::move(from);
    }

    template <typename m_DataType, typename m_DeleterType>
    typename UniquePointer<m_DataType[], m_DeleterType>::SelfType &
    UniquePointer<m_DataType[], m_DeleterType>::operator=(
        typename UniquePointer<m_DataType[], m_DeleterType>::SelfType &&from)
    {
        UniquePointer<m_DataType[], m_DeleterType>::ParentType::operator=(std::move(from));
        return *this;
    }

    template <typename m_DataType, typename m_DeleterType>
    NTL_INLINE
        typename UniquePointer<m_DataType[], m_DeleterType>::DataType &
        UniquePointer<m_DataType[], m_DeleterType>::operator*() const
    {
        if (Pointer<m_DataType>::is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType, typename m_DeleterType> NTL_INLINE typename UniquePointer<m_DataType[], m_DeleterType>::DataType &UniquePointer<m_DataType[], m_DeleterType>::operator*() const"));
        return *get();
    }

    template <typename m_DataType, typename m_DeleterType>
    NTL_INLINE
        typename UniquePointer<m_DataType[], m_DeleterType>::DataType *
        UniquePointer<m_DataType[], m_DeleterType>::operator->() const
    {
        if (Pointer<m_DataType>::is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType, typename m_DeleterType> NTL_INLINE typename UniquePointer<m_DataType[], m_DeleterType>::DataType *UniquePointer<m_DataType[], m_DeleterType>::operator->() const"));
        return get();
    }

    template <typename m_DataType, typename m_DeleterType>
    NTL_INLINE
        typename UniquePointer<m_DataType[], m_DeleterType>::DataType &
        UniquePointer<m_DataType[], m_DeleterType>::operator[](std::size_t index)
    {
        if (Pointer<m_DataType>::is_nullptr())
            throw NullPointerException(NTL_CSTRING("template <typename m_DataType, typename m_DeleterType> NTL_INLINE typename UniquePointer<m_DataType[], m_DeleterType>::DataType &UniquePointer<m_DataType[], m_DeleterType>::operator[](std::size_t index)"));
        return get()[index];
    }

    template <typename m_DataType, typename m_DeleterType>
    typename UniquePointer<m_DataType[], m_DeleterType>::DataType *
    UniquePointer<m_DataType[], m_DeleterType>::get() const
    {
        return UniquePointer<m_DataType[], m_DeleterType>::ParentType::get();
    }

    template <typename DataType, typename... ArgsType>
    UniquePointer<DataType, BasicDeleter<DataType>>
    make_unique(
        const ArgsType &...args)
    {
        return UniquePointer<DataType,
                             BasicDeleter<
                                 DataType>>(
            new DataType(args...));
    }

} // namespace ntl

#endif