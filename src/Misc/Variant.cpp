#ifndef __NEUTRONTL_MISC_VARIANT_CPP__
#define __NEUTRONTL_MISC_VARIANT_CPP__

#include "Variant.hpp"

namespace ntl
{
    template <typename ValueType>
    Variant::Variant(
        const ValueType &value)
        : ParentType(value) {}

    template <typename ValueType>
    Variant::operator ValueType() const
    {
        return std::get<ValueType>(*this);
    }

} // namespace ntl

#endif
