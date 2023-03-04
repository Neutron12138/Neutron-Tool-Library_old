#ifndef __NEUTRONTL_STRING_STLTYPE_HPP__
#define __NEUTRONTL_STRING_STLTYPE_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Object.hpp"

namespace ntl
{
    /// @brief 标准库中的类型
    /// @tparam m_CharType 字符类型
    /// @tparam m_TraitsType 字符特点类型
    /// @tparam m_AllocatorType 分配器类型
    template <typename m_CharType = char, typename m_TraitsType = std::char_traits<m_CharType>, typename m_AllocatorType = std::allocator<m_CharType>>
    class NTL_ALIGN STLType : public Object
    {
    public:
        /// @brief 字符类型
        using CharType = m_CharType;
        /// @brief 字符特点类型
        using TraitsType = m_TraitsType;
        /// @brief 分配器类型
        using AllocatorType = m_AllocatorType;

        /// @brief 输入流类型
        using InputStreamType = std::basic_istream<CharType, TraitsType>;
        /// @brief 输出流类型
        using OutputStreamType = std::basic_ostream<CharType, TraitsType>;
        /// @brief 输入输出流类型
        using IOStreamType = std::basic_iostream<CharType, TraitsType>;

        /// @brief 字符串类型
        using StringType = std::basic_string<CharType, TraitsType, AllocatorType>;
        /// @brief 字符串输入流类型
        using InputStringStreamType = std::basic_istringstream<CharType, TraitsType, AllocatorType>;
        /// @brief 字符串输出流类型
        using OutputStringStreamType = std::basic_ostringstream<CharType, TraitsType, AllocatorType>;
        /// @brief 字符串输入输出流类型
        using StringStreamType = std::basic_stringstream<CharType, TraitsType, AllocatorType>;

        /// @brief 文件输入流类型
        using InputFileStreamType = std::basic_ifstream<CharType, TraitsType>;
        /// @brief 文件输出流类型
        using OutputFileStreamType = std::basic_ofstream<CharType, TraitsType>;
        /// @brief 文件输入输出流类型
        using FileStreamType = std::basic_fstream<CharType, TraitsType>;

        using SelfType = STLType<CharType, TraitsType, AllocatorType>;
        using ParentType = Object;

    public:
        constexpr STLType() noexcept = default;
        constexpr explicit STLType(const SelfType &from) noexcept = default;
        ~STLType() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;
    };

    /// @brief 标准库单字节字符类型
    using STypes = STLType<char>;
    /// @brief 标准库宽字符类型
    using SWTypes = STLType<wchar_t>;

} // namespace ntl

#endif