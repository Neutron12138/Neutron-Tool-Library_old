#ifndef __NEUTRONTL_MEMORY_UNIQUEPOINTER_HPP__
#define __NEUTRONTL_MEMORY_UNIQUEPOINTER_HPP__

#include <memory>
#include "Pointer.hpp"
#include "BasicDeleter.hpp"

namespace ntl
{
    /// @brief 专有指针类型，只能有一个指针拥有资源
    /// @tparam m_DataType 指针类型
    /// @tparam m_DeleterType 删除器类型
    template <typename m_DataType, typename m_DeleterType = BasicDeleter<m_DataType>>
    class NTL_ALIGN UniquePointer : public Pointer<m_DataType>, public std::unique_ptr<m_DataType, m_DeleterType>
    {
    public:
        using DataType = m_DataType;
        using DeleterType = m_DeleterType;
        using PointerType = Pointer<DataType[]>;
        using AutoPointerType = std::unique_ptr<DataType, DeleterType>;

        using SelfType = UniquePointer<DataType, DeleterType>;
        using ParentType = AutoPointerType;

    public:
        UniquePointer() = default;
        NTL_EXPLICIT UniquePointer(DataType *ptr);
        NTL_EXPLICIT UniquePointer(DataType *ptr, DeleterType deleter);
        NTL_EXPLICIT UniquePointer(const SelfType &from) = delete;
        NTL_EXPLICIT UniquePointer(SelfType &&from);
        NTL_VIRTUAL ~UniquePointer() NTL_OVERRIDE = default;

    public:
        SelfType &operator=(const SelfType &from) = delete;
        SelfType &operator=(SelfType &&from);
        DataType &operator*() const NTL_OVERRIDE;
        DataType *operator->() const NTL_OVERRIDE;

    public:
        DataType *get() const NTL_OVERRIDE;
    };

    /// @brief 专有数组类型，只能有一个指针拥有资源
    /// @tparam m_DataType 指针类型
    /// @tparam m_DeleterType 删除器类型
    template <typename m_DataType, typename m_DeleterType>
    class NTL_ALIGN UniquePointer<m_DataType[], m_DeleterType> : public Pointer<m_DataType[]>, public std::unique_ptr<m_DataType[], m_DeleterType>
    {
    public:
        using DataType = m_DataType;
        using DeleterType = m_DeleterType;
        using PointerType = Pointer<DataType[]>;
        using AutoPointerType = std::unique_ptr<DataType[], DeleterType>;

        using SelfType = UniquePointer<DataType[], DeleterType>;
        using ParentType = AutoPointerType;

    public:
        UniquePointer() = default;
        NTL_EXPLICIT UniquePointer(DataType *ptr);
        NTL_EXPLICIT UniquePointer(DataType *ptr, DeleterType deleter);
        NTL_EXPLICIT UniquePointer(const SelfType &from) = delete;
        NTL_EXPLICIT UniquePointer(SelfType &&from);
        NTL_VIRTUAL ~UniquePointer() NTL_OVERRIDE = default;

    public:
        SelfType &operator=(const SelfType &from) = delete;
        SelfType &operator=(SelfType &&from);
        DataType &operator*() const NTL_OVERRIDE;
        DataType *operator->() const NTL_OVERRIDE;
        DataType &operator[](std::size_t index) const NTL_OVERRIDE;

    public:
        DataType *get() const NTL_OVERRIDE;
    };

    /// @brief 创建一个新的专有指针
    /// @tparam DataType 数据类型
    /// @tparam ...ArgsType 参数类型列表
    /// @param ...args 参数列表
    /// @return 指针
    template <typename DataType, typename... ArgsType>
    UniquePointer<DataType, BasicDeleter<DataType>> make_unique(const ArgsType &...args);

} // namespace ntl

#endif