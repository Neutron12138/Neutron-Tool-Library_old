#ifndef __NEUTRONTL_DEBUG_HPP__
#define __NEUTRONTL_DEBUG_HPP__

#include <functional>
#include "Base/Object.hpp"
#include "String/StringUtils.hpp"
#include "Exception/Exception.hpp"
#include "Exception/CaughtException.hpp"

#ifndef NEUTRONTL_CONFIG_NO_DEBUG

// 如果定义DEBUG或_DEBUG
#if defined(DEBUG) || defined(_DEBUG)
// 什么都不干:)
#endif

// 设置调试输出函数
#define NTL_set_debug_output(func) __ntl__::set_debug_output_func(func)

// 输出调试信息
#define NTL_debug_output(args...) __ntl__::debug_output(args)

// 调试
#define NTL_debug(func_name, statement)                                       \
    try                                                                       \
    {                                                                         \
        statement                                                             \
    }                                                                         \
    catch (const ntl::CaughtException &exception)                             \
    {                                                                         \
        NTL_debug_output(                                                     \
            ntl::CaughtException(                                             \
                exception,                                                    \
                NTL_MAKE_STATEMENT_INFO(func_name)));                         \
    }                                                                         \
    catch (const ntl::Exception &exception)                                   \
    {                                                                         \
        NTL_debug_output(                                                     \
            ntl::CaughtException(                                             \
                exception,                                                    \
                NTL_MAKE_STATEMENT_INFO(func_name)));                         \
    }                                                                         \
    catch (const std::exception &exception)                                   \
    {                                                                         \
        NTL_debug_output(                                                     \
            ntl::CaughtException(                                             \
                exception,                                                    \
                NTL_MAKE_STATEMENT_INFO(func_name)));                         \
    }                                                                         \
    catch (...)                                                               \
    {                                                                         \
        NTL_debug_output(                                                     \
            NTL_STRING("An unknown exception was caught during debugging\n"), \
            NTL_MAKE_STATEMENT_INFO(func_name));                              \
    }

// 调试
#define NTL_debug_throw(func_name, statement)                               \
    try                                                                     \
    {                                                                       \
        statement                                                           \
    }                                                                       \
    catch (const ntl::CaughtException &exception)                           \
    {                                                                       \
        throw ntl::CaughtException(                                         \
            exception,                                                      \
            NTL_MAKE_STATEMENT_INFO(func_name));                            \
    }                                                                       \
    catch (const ntl::Exception &exception)                                 \
    {                                                                       \
        throw ntl::CaughtException(                                         \
            exception,                                                      \
            NTL_MAKE_STATEMENT_INFO(func_name));                            \
    }                                                                       \
    catch (const std::exception &exception)                                 \
    {                                                                       \
        throw ntl::CaughtException(                                         \
            exception,                                                      \
            NTL_MAKE_STATEMENT_INFO(func_name));                            \
    }                                                                       \
    catch (...)                                                             \
    {                                                                       \
        throw ntl::Exception(                                               \
            NTL_STRING("exception"),                                        \
            NTL_STRING("An unknown exception was caught during debugging"), \
            NTL_MAKE_STATEMENT_INFO(func_name));                            \
    }

namespace __ntl__
{
    std::function<void(const ntl::Char *)> debug_output_func;

    template <typename FuncType>
    void set_debug_output_func(FuncType func);

    template <typename... ArgsType>
    void debug_output(ArgsType &&...args);

} // namespace __ntl__

#endif

#endif
