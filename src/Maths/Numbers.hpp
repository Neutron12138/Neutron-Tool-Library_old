#ifndef __NEUTRONTL_MATHS_NUMBERS_HPP__
#define __NEUTRONTL_MATHS_NUMBERS_HPP__

#include "../Base/BasicObject.hpp"

namespace ntl
{
    namespace Numbers
    {
        struct Zero : public BasicObject
        {
            using SelfType = Zero;
            using ParentType = BasicObject;

            template <typename NumberType>
            operator NumberType() const;
        };

        struct One : public BasicObject
        {
            using SelfType = One;
            using ParentType = BasicObject;

            template <typename NumberType>
            operator NumberType() const;
        };

    } // namespace Numbers

} // namespace ntl

#endif
