#ifndef __NEUTRONTL_SCRIPT_TOKEN_HPP__
#define __NEUTRONTL_SCRIPT_TOKEN_HPP__

#include "../Base/Type.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    namespace script
    {
        /// @brief 标识符
        namespace Token
        {
            /// @brief 忽略空格
            static const String ignore_spaces = NTL_STRING("(?:[ ]+)?");

            /// @brief 忽略制表符
            static const String ignore_tabs = NTL_STRING("(?:[\t]+)?");

            /// @brief 需要至少一个空格
            static const String need_space = NTL_STRING("[ ]+");

            /// @brief 通配符，可以匹配任意字符
            static const String wildcard = NTL_STRING("(.*)");

            /// @brief 声明变量
            static const String declare_variable = NTL_STRING("var");

            /// @brief 赋值符
            static const String assignment = NTL_STRING("=");

            /// @brief 忽略空白
            static const String ignore_blank = ignore_tabs + ignore_spaces;
        } // namespace Token

    } // namespace script

} // namespace ntl

#endif