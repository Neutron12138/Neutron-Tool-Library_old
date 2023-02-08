#ifndef __NEUTRONTL_STRING_STRINGUTILS_HPP__
#define __NEUTRONTL_STRING_STRINGUTILS_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <vector>
#include "../Base/Object.hpp"
#include "../Base/Type.hpp"

#ifdef NEUTRONTL_CONFIG_USE_WCHAR
#define NTL_CSTRING(str) L##str
#define NTL_STRING(str) ntl::String(L##str)
#else
#define NTL_CSTRING(str) str
#define NTL_STRING(str) ntl::String(str)
#endif

namespace ntl
{
    /// @brief 字符串的工具类
    class NTL_ALIGN StringUtils : public Object
    {
    public:
        using SelfType = StringUtils;
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
        StringUtils() = default;
        explicit StringUtils(const SelfType &from) = default;
        ~StringUtils() override = default;

    public:
        inline SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 上一次调用load_string_from_stream()后的状态
        Status load_string_from_stream_status = Status::NotCalled;

        /// @brief 上一次调用load_string_from_stream()后的结果
        String load_string_from_stream_result;

        /// @brief 从输入流加载字符串
        /// @param is 输入流
        /// @return 结果
        const String &load_string_from_stream(InputStream &is);

    public:
        /// @brief 上一次调用load_string_from_file()后的状态
        Status load_string_from_file_status = Status::NotCalled;

        /// @brief 上一次调用load_string_from_file()后的结果
        String load_string_from_file_result;

        /// @brief 从文件加载字符串
        /// @param filename 文件名
        /// @return 结果
        const String &load_string_from_file(const std::string &filename);

    public:
#ifdef NEUTRON_CONFIG_USE_WCHAR
        /// @brief 转换为宽字符字符串
        /// @param str 字符串
        /// @return 宽字符字符串
        static std::wstring to_stl_string(const std::string &str);
#else
        /// @brief 转换为宽字符字符串
        /// @param str 字符串
        /// @return 宽字符字符串
        static std::string to_stl_string(const std::string &str);
#endif

    public:
        /// @brief 转换为字符串，重载函数之一
        /// @return 转换后的结果
        static String to_string();

        /// @brief 转换为字符串，重载函数之一
        /// @tparam ArgT 参数类型
        /// @param arg 参数
        /// @return 转换后的结果
        template <typename ArgT>
        static String to_string(const ArgT &arg);

        /// @brief 转换为字符串，重载函数之一
        /// @tparam ArgT 参数类型
        /// @tparam ...ArgsT 参数类型列表
        /// @param arg 参数
        /// @param ...args 参数列表
        /// @return 转换后的结果
        template <typename ArgT, typename... ArgsT>
        static String to_string(const ArgT &arg, const ArgsT &...args);

    public:
        /// @brief 匹配
        /// @param data 数据
        /// @param regex 正则表达式
        /// @param flag 标志
        /// @return 是否匹配到
        static bool match(const String &data, const Regex &regex, std::regex_constants::match_flag_type flag = std::regex_constants::match_default);

        /// @brief 搜索
        /// @param data 数据
        /// @param match 搜索结果
        /// @param regex 正则表达式
        /// @param flag 标志
        /// @return 是否匹配到
        static bool search(const String &data, Match &match, const Regex &regex, std::regex_constants::match_flag_type flag = std::regex_constants::match_default);

        /// @brief 替换
        /// @param data 数据
        /// @param regex 正则表达式
        /// @param fmt 替换数据
        /// @param flag 标志
        /// @return 是否匹配到
        static String replace(const String &data, const Regex &regex, const String &fmt, std::regex_constants::match_flag_type flag = std::regex_constants::match_default);

        /// @brief 替换所有
        /// @param data 数据
        /// @param regex 正则表达式
        /// @param fmt 替换数据
        /// @param flag 标志
        /// @return 是否匹配到
        static String replace_all(const String &data, const Regex &regex, const String &fmt, std::regex_constants::match_flag_type flag = std::regex_constants::match_default);

        /// @brief 分割字符串
        /// @param data 数据
        /// @param reg 分割符的正则表达式
        /// @param flag 标志
        /// @return 分割结果
        static std::vector<String> split(const String &data, const String &reg, std::regex_constants::match_flag_type flag = std::regex_constants::match_default);

        /// @brief 按行分割字符串
        /// @param data 数据
        /// @return 分割结果
        static std::vector<String> split_by_line(const String &data);
    };

    std::wostream &operator<<(std::wostream &os, const std::string &str);
} // namespace ntl

#endif