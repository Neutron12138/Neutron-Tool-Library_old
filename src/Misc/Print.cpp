#ifndef __NEUTRONTL_MISC_PRINT_CPP__
#define __NEUTRONTL_MISC_PRINT_CPP__

#include "Print.hpp"

namespace ntl
{
    template <typename IteratorType>
    void
    Print::print_array(
        OutputStream &os,
        const IteratorType &begin,
        const IteratorType &end,
        const String &delimiter)
    {
        for (auto iter = begin; iter != end; iter++)
        {
            os << *iter << delimiter;
        }
        os << std::endl;
    }
} // namespace ntl

#endif