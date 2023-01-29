#ifndef __NEUTRONTL_BASE_TYPE_HPP__
#define __NEUTRONTL_BASE_TYPE_HPP__

#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <fstream>

namespace ntl
{
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
    
} // namespace ntl

#endif