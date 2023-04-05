#ifndef __NEUTRONTL_BASE_STDIOTYPE_CPP__
#define __NEUTRONTL_BASE_STDIOTYPE_CPP__

#include "StdIOType.hpp"

namespace ntl
{
    template <typename StreamTraitsType,
              typename StringTraitsType,
              typename StringAllocatorType>
    std::basic_ostream<wchar_t, StreamTraitsType> &
    operator<<(
        std::basic_ostream<
            wchar_t,
            StreamTraitsType> &os,
        const std::basic_string<
            char,
            StringTraitsType,
            StringAllocatorType> &str)
    {
        for (auto iter = str.cbegin(); iter != str.cend(); iter++)
            os.put(static_cast<wchar_t>(*iter));
        return os;
    }

} // namespace ntl

#endif