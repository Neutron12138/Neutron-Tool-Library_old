#ifndef __NEUTRONTL_STRING_STRINGSTREAM_CPP__
#define __NEUTRONTL_STRING_STRINGSTREAM_CPP__

#include "StringStream.hpp"

namespace ntl
{
    BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicStringStream(const typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType &wstr,
                                                                                             std::ios_base::openmode mode) : BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType(wstr, mode) {}

    typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StringType BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::to_string() const
    {
        typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType string = BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType::str();
        typename BasicStringStream<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StringType result(string);
        return result;
    }
} // namespace ntl

#endif