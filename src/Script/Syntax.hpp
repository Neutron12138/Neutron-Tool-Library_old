#ifndef __NEUTRONTL_SCRIPT_SYNTAX_HPP__
#define __NEUTRONTL_SCRIPT_SYNTAX_HPP__

#include "Token.hpp"

namespace ntl
{
    namespace script
    {
        /// @brief 语法
        namespace Syntax
        {
            /// @brief 对一个变量赋值
            static const String assignment =
                Token::ignore_blank +
                Token::wildcard + // 变量名（1）
                Token::ignore_blank +
                Token::assignment + // "="
                Token::ignore_blank +
                Token::wildcard + // 值（2）
                Token::ignore_blank;

            /// @brief 声明变量
            static const String declare_variable =
                Token::ignore_blank +
                Token::declare_variable + // 关键字var
                Token::ignore_blank +
                Token::wildcard + // 变量名列表（1）
                Token::ignore_blank;

        } // namespace Syntax

    } // namespace script

} // namespace ntl

#endif