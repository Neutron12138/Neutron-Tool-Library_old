#ifndef __NEUTRONTL_REFLECTION_NONSTATICMETHOD_HPP__
#define __NEUTRONTL_REFLECTION_NONSTATICMETHOD_HPP__

#include "Method.hpp"

namespace ntl
{
    /// @brief 非静态方法
    class NTL_ALIGN NonStaticMethod : public Method<void (BasicObject::*)()>
    {
    public:
        using MethodPointer = void (BasicObject::*)();

        using SelfType = NonStaticMethod;
        using ParentType = Method<MethodPointer>;

    public:
        NonStaticMethod() = default;
        template <typename MethodType>
        explicit NonStaticMethod(MethodType pointer, SizeT args_count);
        template <typename MethodType>
        explicit NonStaticMethod(MethodType pointer, SizeT args_count, const MethodSign &sign);
        explicit NonStaticMethod(const SelfType &from) = default;
        ~NonStaticMethod() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        template <typename ReturnType, typename... ArgsType>
        ReturnType call(void *object, ArgsType &&...args) const;
    };

} // namespace ntl

#endif