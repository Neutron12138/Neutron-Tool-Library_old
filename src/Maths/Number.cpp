#ifndef __NEUTRONTL_MATHS_NUMBER_CPP__
#define __NEUTRONTL_MATHS_NUMBER_CPP__

#include "Number.hpp"

namespace ntl
{
    namespace Numbers
    {
        template <typename NumberType>
        Zero::operator NumberType() const
        {
            return static_cast<NumberType>(0);
        }

        template <typename NumberType>
        One::operator NumberType() const
        {
            return static_cast<NumberType>(1);
        }

    } // namespace Numbers

} // namespace ntl

#endif
