#ifndef __NEUTRONTL_MEMORY_WEAKPOINTER_HPP__
#define __NEUTRONTL_MEMORY_WEAKPOINTER_HPP__

#include <memory>
#include "../Base/Object.hpp"
#include "SharedPointer.hpp"

namespace ntl
{
    /// @brief 弱引用指针，只是一个观察器
    /// @tparam m_DataType 数据类型
    template <typename m_DataType>
    class NTL_ALIGN WeakPointer : public Object, public std::weak_ptr<m_DataType>
    {
    public:
        using DataType = m_DataType;
        using AutoPointerType = std::weak_ptr<DataType>;
        using SharedPointerType = SharedPointer<DataType>;

        using SelfType = WeakPointer<DataType>;
        using ParentType = AutoPointerType;

    public:
        WeakPointer() = default;
        WeakPointer(const SharedPointerType &ptr);
        WeakPointer(const SelfType &from) = default;
        ~WeakPointer() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        SelfType &operator=(const SharedPointerType &ptr);
    };
} // namespace ntl

#endif