#ifndef __NEUTRONTL_BASE_STDIOTYPE_HPP__
#define __NEUTRONTL_BASE_STDIOTYPE_HPP__

#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <fstream>
#include "../Misc/ClassMerger.hpp"

namespace ntl
{
#ifdef NEUTRONTL_CONFIG_USE_WCHAR

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