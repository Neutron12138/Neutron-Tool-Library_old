#ifndef __NEUTRONTL_MEMORY_SHAREDPOINTER_HPP__
#define __NEUTRONTL_MEMORY_SHAREDPOINTER_HPP__

#include <memory>
#include "Pointer.hpp"

namespace ntl
{
    /// @brief 共享指针类型，所有指针共享同一份资源
    /// @tparam m_DataType 指针类型
    template <typename m_DataType>
    class NTL_ALIGN SharedPointer : public Pointer<m_DataType>, public std::shared_ptr<m_DataType>
    {
    public:
        using DataType = m_DataType;
        using PointerType = Pointer<DataType>;
        using AutoPointerType = std::shared_ptr<DataType>;

        using SelfType = SharedPointer<DataType>;
        using ParentType = AutoPointerType;

    public:
        SharedPointer() = default;
        NTL_EXPLICIT SharedPointer(DataType *ptr);
        template <typename DeleterType>
        NTL_EXPLICIT SharedPointer(DataType *ptr, DeleterType deleter);
        NTL_EXPLICIT SharedPointer(const SelfType &from) = default;
        NTL_VIRTUAL ~SharedPointer() NTL_OVERRIDE = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        DataType &operator*() const NTL_OVERRIDE;
        DataType *operator->() const NTL_OVERRIDE;

    public:
        DataType *get() const NTL_OVERRIDE;
    };

    /// @brief 创建一个新的共享指针
    /// @tparam DataType 数据类型
    /// @tparam ...ArgsType 参数类型列表
    /// @param ...args 参数列表
    /// @return 指针
    template <typename DataType, typename... ArgsType>
    SharedPointer<DataType> make_shared(const ArgsType &...args);

} // namespace ntl

#endif