#ifndef __NEUTRONTL_REFLECTION_METHOD_HPP__
#define __NEUTRONTL_REFLECTION_METHOD_HPP__

#include "Member.hpp"

namespace ntl
{
    class Reflectible;

    /// @brief 方法
    template <typename m_MethodPointer>
    class Method : public Member<m_MethodPointer>
    {
    public:
        /// @brief 储存用的类型
        using MethodPointer = m_MethodPointer;

        using SelfType = Method;
        using ParentType = Member<m_MethodPointer>;

    protected:
        /// @brief 方法参数总数
        SizeT m_args_count = 0;

    public:
        Method() = default;
        template <typename MethodType>
        explicit Method(MethodType pointer, SizeT args_count);
        explicit Method(const SelfType &from) = default;
        ~Method() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        SizeT get_args_count() const;
    };

} // namespace ntl

#endif