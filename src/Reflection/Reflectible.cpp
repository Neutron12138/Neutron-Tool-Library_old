#ifndef __NEUTRONTL_REFLECTION_REFLECTIBLE_CPP__
#define __NEUTRONTL_REFLECTION_REFLECTIBLE_CPP__

#include "Reflectible.hpp"
#include "Details.hpp"

namespace ntl
{
    Details
    Reflectible::get_reflection_details()
    {
        Details::StaticMethodMap methods;

        methods.insert(
            Details::StaticMethodMap::value_type(
                Details::get_reflection_details_name,
                StaticMethod(&Reflectible::get_reflection_details, 0)));
        methods.insert(
            Details::StaticMethodMap::value_type(
                Details::construction_name,
                StaticMethod(&Reflectible::construct, 0)));
        methods.insert(
            Details::StaticMethodMap::value_type(
                Details::destruction_name,
                StaticMethod(&Reflectible::destruct, 1)));

        return Details(
            sizeof(Reflectible),
            Details::NonStaticFieldMap(),
            Details::StaticFieldMap(),
            Details::NonStaticMethodMap(),
            methods);
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
        delete reinterpret_cast<Reflectible *>(ptr);
    }

} // namespace ntl

#endif