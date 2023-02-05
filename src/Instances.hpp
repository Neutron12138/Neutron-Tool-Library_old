#ifndef __NEUTRONTL_INSTANCES_HPP__
#define __NEUTRONTL_INSTANCES_HPP__

#include <iostream>
#include <glm/glm.hpp>
#include "String/StringUtils.hpp"
#include "Time/Time.hpp"
#include "Base/Type.hpp"
#include "Log/Log.hpp"

namespace ntl
{
    /// @brief 日志对象
    static Log log;
    /// @brief 字符串工具
    static StringUtils string_utils;

    /// @brief 单位矩阵2*2
    static glm::mat2 const IdentityMatrix2 = glm::mat2(1.0f);
    /// @brief 单位矩阵3*3
    static glm::mat3 const IdentityMatrix3 = glm::mat3(1.0f);
    /// @brief 单位矩阵4*4
    static glm::mat4 const IdentityMatrix4 = glm::mat4(1.0f);

    /// @brief 0秒
    static Time const ZeroSecond = Time(static_cast<clock_t>(0));
    /// @brief 1秒
    static Time const OneSecond = Time(static_cast<clock_t>(CLOCKS_PER_SEC));

#ifndef NEUTRONTL_CONFIG_USE_CHAR
    /// @brief 标准输入流
    static InputStream &nin = std::wcin;
    /// @brief 标准输出流
    static OutputStream &nout = std::wcout;
    /// @brief 标准错误输出流
    static OutputStream &nerr = std::wcerr;
    /// @brief 标准日志输出流
    static OutputStream &nlog = std::wclog;
#else
    /// @brief 标准输入流
    static InputStream &nin = std::cin;
    /// @brief 标准输出流
    static OutputStream &nout = std::cout;
    /// @brief 标准错误输出流
    static OutputStream &nerr = std::cerr;
    /// @brief 标准日志输出流
    static OutputStream &nlog = std::clog;
#endif

} // namespace ntl

#endif