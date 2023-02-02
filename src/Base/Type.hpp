#ifndef __NEUTRONTL_BASE_TYPE_HPP__
#define __NEUTRONTL_BASE_TYPE_HPP__

#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <fstream>
#include <cstdint>

namespace ntl
{
    // 数据类型

    /// @brief 字节类型
    using Byte = signed char;

    /// @brief 无符号字节类型
    using UByte = unsigned char;

    /// @brief 短整数类型
    using Short = signed short;

    /// @brief 无符号短整数类型
    using UShort = unsigned short;

    /// @brief 整数类型
    using Int = signed int;

    /// @brief 无符号整数类型
    using UInt = unsigned int;

    /// @brief 长整数类型
    using Long = signed long;

    /// @brief 无符号长整数类型
    using ULong = unsigned long;

    /// @brief 超长长整数类型
    using LLong = signed long long;

    /// @brief 无符号超长长整数类型
    using ULLong = unsigned long long;

    /// @brief 浮点数类型
    using Float = float;

    /// @brief 双精度数类型
    using Double = double;

    // 字符类型

#ifndef NEUTRONTL_CONFIG_USE_CHAR

    /// @brief 字符类型
    using Char = wchar_t;

    /// @brief 字符串类型
    using String = std::wstring;

    /// @brief 字符串流类型
    using StringStream = std::wstringstream;

    /// @brief 字符串输入流类型
    using InputStringStream = std::wistringstream;

    /// @brief 字符串输出流类型
    using OutputStringStream = std::wostringstream;

    /// @brief 正则表达式类型
    using Regex = std::wregex;

    /// @brief 匹配结果类型
    using Match = std::wsmatch;

    /// @brief 输入输出流类型
    using IOStream = std::wiostream;

    /// @brief 输入流类型
    using InputStream = std::wistream;

    /// @brief 输出流类型
    using OutputStream = std::wostream;

    /// @brief 文件输入输出流
    using FileStream = std::wfstream;

    /// @brief 文件输入流
    using InputFileStream = std::wifstream;

    /// @brief 文件输出流
    using OutputFileStream = std::wofstream;

#else

    /// @brief 字符类型
    using Char = char;

    /// @brief 字符串类型
    using String = std::string;

    /// @brief 字符串流类型
    using StringStream = std::stringstream;

    /// @brief 字符串输入流类型
    using InputStringStream = std::istringstream;

    /// @brief 字符串输出流类型
    using OutputStringStream = std::ostringstream;

    /// @brief 正则表达式类型
    using Regex = std::regex;

    /// @brief 匹配结果类型
    using Match = std::smatch;

    /// @brief 输入输出流类型
    using IOStream = std::iostream;

    /// @brief 输入流类型
    using InputStream = std::istream;

    /// @brief 输出流类型
    using OutputStream = std::ostream;

    /// @brief 文件输入输出流
    using FileStream = std::fstream;

    /// @brief 文件输入流
    using InputFileStream = std::ifstream;

    /// @brief 文件输出流
    using OutputFileStream = std::ofstream;

#endif
} // namespace ntl

#endif