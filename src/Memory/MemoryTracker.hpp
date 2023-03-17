#ifndef __NEUTRONTL_MEMORY_MEMORYTRACKER_HPP__
#define __NEUTRONTL_MEMORY_MEMORYTRACKER_HPP__

#include "../Base/BasicObject.hpp"

namespace ntl
{
    /// @brief 内存跟踪器
    /// @tparam m_ClassType 类类型
    template <typename m_ClassType>
    class MemoryTracker : public BasicObject
    {
    public:
        /// @brief 类类型
        using ClassType = m_ClassType;

        using SelfType = MemoryTracker<ClassType>;
        using ParentType = ClassType;

    protected:
        /// @brief 数据
        ClassType m_data;

    public:
        MemoryTracker() = default;
        template <typename... ArgsType>
        MemoryTracker(ArgsType &&...args);
        MemoryTracker(const ClassType &from);
        MemoryTracker(const SelfType &from) = default;
        ~MemoryTracker() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        operator ClassType();
        operator ClassType() const;

    public:
        /// @brief 作为m_ClassType
        /// @return m_ClassType类型的本对象
        ClassType &as();

        /// @brief 作为m_ClassType
        /// @return m_ClassType类型的本对象
        const ClassType &as() const;
    };

} // namespace ntl

#endif