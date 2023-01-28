#ifndef __NEUTRONTL_STRING_STRINGUTILS_HPP__
#define __NEUTRONTL_STRING_STRINGUTILS_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "../Base/Object.hpp"

namespace ntl
{
    /// @brief 字符串的工具类
    /// @tparam m_StringType 字符串类型
    /// @tparam m_StringStreamType 字符串流类型
    /// @tparam m_FileStreamType
    /// @tparam m_InputStreamType
    template <typename m_StringType, typename m_StringStreamType, typename m_InputStreamType, typename m_InputFileStreamType>
    class BasicStringUtils : public Object
    {
    public:
        using StringType = m_StringType;
        using StringStreamType = m_StringStreamType;
        using InputStreamType = m_InputStreamType;
        using InputFileStreamType = m_InputFileStreamType;

        using SelfType = BasicStringUtils<StringType, StringStreamType, InputStreamType, InputFileStreamType>;
        using ParentType = Object;

        /// @brief 状态枚举
        enum Status
        {
            /// @brief 失败
            Failure = 0,

            /// @brief 成功
            Success,

            /// @brief 还未被调用
            NotCalled,

            /// @brief 状态总数
            Count,
        };

    public:
        BasicStringUtils() = default;
        BasicStringUtils(const SelfType &from) = default;
        ~BasicStringUtils() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 上一次调用load_string_from_stream()后的状态
        Status load_string_from_stream_status = Status::NotCalled;

        /// @brief 上一次调用load_string_from_stream()后的结果
        StringType load_string_from_stream_result;

        /// @brief 从输入流加载字符串
        /// @param is 输入流
        /// @return 结果
        const StringType &load_string_from_stream(InputStreamType &is);

    public:
        /// @brief 上一次调用load_string_from_file()后的状态
        Status load_string_from_file_status = Status::NotCalled;

        /// @brief 上一次调用load_string_from_file()后的结果
        StringType load_string_from_file_result;

        /// @brief 从文件加载字符串
        /// @param filename 文件名
        /// @return 结果
        const StringType &load_string_from_file(const std::string &filename);

    public:
        /// @brief 转换为字符串，重载函数之一
        /// @return 转换后的结果
        static StringType to_string();

        /// @brief 转换为字符串，重载函数之一
        /// @tparam ArgT 参数类型
        /// @param arg 参数
        /// @return 转换后的结果
        template <typename ArgT>
        static StringType to_string(const ArgT &arg);

        /// @brief 转换为字符串，重载函数之一
        /// @tparam ArgT 参数类型
        /// @tparam ...ArgsT 参数类型列表
        /// @param arg 参数
        /// @param ...args 参数列表
        /// @return 转换后的结果
        template <typename ArgT, typename... ArgsT>
        static StringType to_string(const ArgT &arg, const ArgsT &...args);
    };

    /// @brief 字符串工具
    using StringUtils = BasicStringUtils<std::string, std::stringstream, std::istream, std::ifstream>;
    /// @brief 宽字符串工具
    using WStringUtils = BasicStringUtils<std::wstring, std::wstringstream, std::wistream, std::wifstream>;
} // namespace ntl

#endif