#ifndef __NEUTRONTL_INSTANCES_HPP__
#define __NEUTRONTL_INSTANCES_HPP__

#include <iostream>
#include <glm/glm.hpp>
#include "String/StringUtils.hpp"
#include "Time/Time.hpp"
#include "Base/Type.hpp"
#include "Log/Log.hpp"
#include "Image/Color.hpp"
#include "Reflection/Reflector.hpp"

namespace ntl
{
    /// @brief 日志对象
    static Log<> log;
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

#ifdef NEUTRONTL_CONFIG_USE_WCHAR
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

    /// @brief 预定义的颜色
    namespace Colors
    {
        /// @brief 红色
        static Color Red = Color(1.0f, 0.0f, 0.0f, 1.0f);

        /// @brief 绿色
        static Color Green = Color(0.0f, 1.0f, 0.0f, 1.0f);

        /// @brief 蓝色
        static Color Blue = Color(0.0f, 0.0f, 1.0f, 1.0f);

        /// @brief 黑色
        static Color Black = Color(0.0f, 0.0f, 0.0f, 1.0f);

        /// @brief 白色
        static Color White = Color(1.0f, 1.0f, 1.0f, 1.0f);

    } // namespace Colors

    /// @brief 默认的反射器
    static Reflector reflector;

} // namespace ntl

#endif