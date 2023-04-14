#ifndef __NEUTRONTL_BASE_COPYABLE_CPP__
#define __NEUTRONTL_BASE_COPYABLE_CPP__

#include "Copyable.hpp"

namespace ntl
{
    typename Copyable::SelfType
    Copyable::copy() const
    {
        return Copyable(*this);
    }

    typename Copyable::SelfType &
    Copyable::swap(
        typename Copyable::SelfType &another)
    {
        return *this;
    }

} // namespace ntl

#endif
