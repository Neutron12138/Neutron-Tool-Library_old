#ifndef __NEUTRONTL_REFLECTION_METHOD_HPP__
#define __NEUTRONTL_REFLECTION_METHOD_HPP__

#include <optional>
#include "Member.hpp"
#include "MethodSign.hpp"

namespace ntl
{ 
    /// @brief 方法
    template <typename m_MethodPointer>
    class NTL_ALIGN Method : public Member<m_MethodPointer>
    {
    public:
        /// @brief 储存用的类型
        using MethodPointer = m_MethodPointer;

        using SelfType = Method;
        using ParentType = Member<m_MethodPointer>;

    protected:
        /// @brief 方法参数总数
        SizeT m_args_count = 0;

        /// @brief 方法的签名
        std::optional<MethodSign> m_sign;

    public:
        Method() = default;
        template <typename MethodType>
        explicit Method(MethodType pointer, SizeT args_count);
        template <typename MethodType>
        explicit Method(MethodType pointer, SizeT args_count, const MethodSign &sign);
        explicit Method(const SelfType &from) = default;
        ~Method() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        SizeT get_args_count() const;

        const std::optional<MethodSign> &get_sign() const;
    };

} // namespace ntl

#endif