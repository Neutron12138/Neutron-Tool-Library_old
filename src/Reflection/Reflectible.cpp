#ifndef __NEUTRONTL_REFLECTION_REFLECTIBLE_CPP__
#define __NEUTRONTL_REFLECTION_REFLECTIBLE_CPP__

#include "Reflectible.hpp"
#include "Details.hpp"

namespace ntl
{
    Details
    Reflectible::get_reflection_details()
    {
        return Details(
            Details::FieldMap(),
            Details::MethodMap(),
            sizeof(Reflectible));
    }

    Reflectible *
    Reflectible::construct()
    {
        return new Reflectible();
    }

    void
    Reflectible::destruct(
        Byte *ptr)
    {
        delete[] reinterpret_cast<Reflectible *>(ptr);
    }

} // namespace ntl

#endif