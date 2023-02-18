#ifndef __NEUTRONTL_MISC_PRINTUTILS_CPP__
#define __NEUTRONTL_MISC_PRINTUTILS_CPP__

#include "PrintUtils.hpp"

namespace ntl
{
    template <typename IteratorType>
    void
    PrintUtils::print_array(
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