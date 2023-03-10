#ifndef __NEUTRONTL_REFLECTION_STATICMETHOD_HPP__
#define __NEUTRONTL_REFLECTION_STATICMETHOD_HPP__

#include "Method.hpp"

namespace ntl
{
    /// @brief 方法
    class StaticMethod : public Method<void (*)()>
    {
    public:
        /// @brief 储存用的方法类型
        using MethodPointer = void (*)();

        using SelfType = StaticMethod;
        using ParentType = Method<MethodPointer>;

    protected:
        /// @brief 参数总数
        SizeT m_args_count;

    public:
        StaticMethod() = default;
        template <typename MethodType>
        explicit StaticMethod(MethodType pointer, SizeT args_count);
        explicit StaticMethod(const SelfType &from) = default;
        ~StaticMethod() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        template <typename ReturnType, typename... ArgsType>
        ReturnType call(ArgsType &&...args) const;
    };

} // namespace ntl

#endif