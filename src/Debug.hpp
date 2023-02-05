#ifndef __NEUTRONTL_DEBUG_HPP__
#define __NEUTRONTL_DEBUG_HPP__

#include <functional>
#include "Base/BasicObject.hpp"

#ifndef NEUTRONTL_CONFIG_NO_DEBUG

// 如果定义DEBUG或_DEBUG
#if defined(DEBUG) || defined(_DEBUG)
// 什么都不干:)
#endif

// 如果定义NEUTRONTL_ENABLE_DEBUG
#ifdef NEUTRONTL_ENABLE_DEBUG
#ifndef NEUTRONTL_DEBUG
#define NEUTRONTL_DEBUG
#endif
#endif

// 禁用调试
/*
#ifdef NEUTRONTL_DEBUG
#undef NEUTRONTL_DEBUG
#endif
*/

#ifdef NEUTRONTL_DEBUG

// 设置调试输出函数
#define NTL_set_debug_output(func) __ntl__::__Debugger__::get().set_output_func(func)
// 输出调试信息
#define NTL_debug_output(str) __ntl__::__Debugger__::get().output(str)

/// @brief NTL的私有命名空间
namespace __ntl__
{
    /// @brief 调试器，单例对象
    class __Debugger__ : public ntl::BasicObject
    {
    public:
        using SelfType = __Debugger__;
        using ParentType = ntl::BasicObject;

        static __Debugger__ &get();

    private:
        std::function<void(const wchar_t *)> m_output_func;

    private:
        __Debugger__() = default;

    public:
        __Debugger__(const SelfType &from) = delete;
        __Debugger__(const SelfType &&from) = delete;
        ~__Debugger__() = default;

    public:
        SelfType &operator=(const SelfType &from) = delete;
        SelfType &operator=(const SelfType &&from) = delete;

    public:
        void set_output_func(const std::function<void(const wchar_t *)> &output_func);
        const std::function<void(const wchar_t *)> &get_output_func() const;
        void output(const wchar_t *str);
    };
} // namespace __ntl__

#endif

#endif

#endif