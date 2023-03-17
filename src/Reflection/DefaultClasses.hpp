#ifndef __NEUTRONTL_REFLECTION_DEFAULTCLASSES_HPP__
#define __NEUTRONTL_REFLECTION_DEFAULTCLASSES_HPP__

#include "Reflector.hpp"

namespace ntl
{
    namespace DefaultClasses
    {
        void register_all(Reflector &reflector);

        template <typename CharType, typename TraitsType, typename AllocatorType>
        Details get_string_details();

        template <typename ElementType, typename AllocatorType>
        Details get_vector_details();

        template <typename ElementType, SizeT size>
        Details get_array_details();

    } // namespace DefaultClasses

} // namespace ntl

#endif