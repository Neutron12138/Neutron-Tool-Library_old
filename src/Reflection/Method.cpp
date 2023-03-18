#ifndef __NEUTRONTL_REFLECTION_METHOD_CPP__
#define __NEUTRONTL_REFLECTION_METHOD_CPP__

#include "Method.hpp"

namespace ntl
{
    template <typename m_MethodPointer>
    template <typename MethodType>
    Method<m_MethodPointer>::Method(
        MethodType pointer,
        SizeT args_count)
        : Method<m_MethodPointer>::ParentType(pointer),
          m_args_count(args_count) {}

    template <typename m_MethodPointer>
    template <typename MethodType>
    Method<m_MethodPointer>::Method(
        MethodType pointer,
        SizeT args_count,
        const MethodSign &sign)
        : Method<m_MethodPointer>::ParentType(pointer),
          m_args_count(args_count),
          m_sign(sign) {}

    template <typename m_MethodPointer>
    SizeT
    Method<m_MethodPointer>::get_args_count() const
    {
        return m_args_count;
    }

    template <typename m_MethodPointer>
    const std::optional<MethodSign> &
    Method<m_MethodPointer>::get_sign() const
    {
        return m_sign;
    }

} // namespace ntl

#endif