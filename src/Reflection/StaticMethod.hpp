#ifndef __NEUTRONTL_REFLECTION_STATICMETHOD_HPP__
#define __NEUTRONTL_REFLECTION_STATICMETHOD_HPP__

#include "Method.hpp"

namespace ntl
{
    /// @brief 静态方法
    class NTL_ALIGN StaticMethod : public Method<void (*)()>
    {
    public:
        using MethodPointer = void (*)();

        using SelfType = StaticMethod;
        using ParentType = Method<MethodPointer>;

    public:
        StaticMethod() = default;
        template <typename MethodType>
        StaticMethod(MethodType pointer, SizeT args_count);
        template <typename MethodType>
        StaticMethod(MethodType pointer, SizeT args_count, const MethodSign &sign);
        StaticMethod(const SelfType &from) = default;
        ~StaticMethod() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        template <typename ReturnType, typename... ArgsType>
        ReturnType call(ArgsType &&...args) const;
    };

} // namespace ntl

#endif