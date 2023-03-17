#ifndef __NEUTRONTL_MEMORY_DEFAULTMEMORYTRACKER_HPP__
#define __NEUTRONTL_MEMORY_DEFAULTMEMORYTRACKER_HPP__

#include "MemoryTracker.hpp"

namespace ntl
{
    /// @brief 默认内存跟踪器
    /// @tparam m_ClassType 类类型
    template <typename m_ClassType>
    class DefaultMemoryTracker : public MemoryTracker<m_ClassType>
    {
    public:
        /// @brief 类类型
        using ClassType = m_ClassType;

        using SelfType = DefaultMemoryTracker<ClassType>;
        using ParentType = MemoryTracker<ClassType>;

    private:
        /// @brief 总数
        static long long m_count;

    public:
        DefaultMemoryTracker();
        template <typename... ArgsType>
        DefaultMemoryTracker(ArgsType &&...args);
        DefaultMemoryTracker(const ClassType &from);
        DefaultMemoryTracker(const SelfType &from);
        ~DefaultMemoryTracker();

    public:
        SelfType &operator=(const SelfType &from) = default;

    private:
        void on_construction();
        void on_destruction();

    public:
        /// @brief 获取总数
        /// @return 构造总数-析构总数
        static long long get_count();
    };

} // namespace ntl

#endif