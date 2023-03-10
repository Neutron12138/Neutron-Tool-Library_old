#ifndef __NEUTRONTL_REFLECTION_NONSTATICMETHOD_HPP__
#define __NEUTRONTL_REFLECTION_NONSTATICMETHOD_HPP__

#include "Method.hpp"

namespace ntl
{
    /// @brief 方法
    class NonStaticMethod : public Method<void (Reflectible::*)()>
    {
    public:
        /// @brief 储存用的方法类型
        using MethodPointer = void (Reflectible::*)();

        using SelfType = NonStaticMethod;
        using ParentType = Method<MethodPointer>;

    protected:
        /// @brief 参数总数
        SizeT m_args_count;

    public:
        NonStaticMethod() = default;
        template <typename MethodType>
        explicit NonStaticMethod(MethodType pointer, SizeT args_count);
        explicit NonStaticMethod(const SelfType &from) = default;
        ~NonStaticMethod() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        template <typename ReturnType, typename... ArgsType>
        ReturnType call(Reflectible &object, ArgsType &&...args) const;
    };

} // namespace ntl

#endif