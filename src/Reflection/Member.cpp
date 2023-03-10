#ifndef __NEUTRONTL_REFLECTION_MEMBER_CPP__
#define __NEUTRONTL_REFLECTION_MEMBER_CPP__

#include <iostream>
#include "Member.hpp"

namespace ntl
{
    template <typename m_MemberPointer>
    template <typename MemberType>
    Member<m_MemberPointer>::Member(
        MemberType pointer)
        : m_pointer(
              reinterpret_cast<
                  typename Member<
                      m_MemberPointer>::MemberPointer>(
                  pointer)) {}

    template <typename m_MemberPointer>
    typename Member<m_MemberPointer>::MemberPointer
    Member<m_MemberPointer>::get_pointer() const
    {
        return m_pointer;
    }

} // namespace ntl

#endif