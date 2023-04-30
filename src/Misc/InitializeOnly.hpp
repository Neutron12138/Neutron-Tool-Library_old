#ifndef __NEUTRONTL_MISC_INITIALIZEONLY_HPP__
#define __NEUTRONTL_MISC_INITIALIZEONLY_HPP__

#include "../Base/NonMoveable.hpp"

namespace ntl
{
    /// @brief 只能初始化的对象，初始化后无法修改，相当于可在运行期确定的常量
    /// @tparam m_DataType 数据类型
    template <typename m_DataType>
    class InitializeOnly : public NonMoveable
    {
    public:
        using DataType = m_DataType;

        using SelfType = InitializeOnly<DataType>;
        using ParentType = NonMoveable;

    protected:
        DataType m_data;

    public:
        template <typename... ArgsType>
        InitializeOnly(ArgsType &&...args);
        ~InitializeOnly() = default;

    public:
        const DataType &operator*() const;
        const DataType &operator->() const;
        operator DataType() const;
    };

} // namespace ntl

#endif
