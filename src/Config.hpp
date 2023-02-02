#ifndef __NEUTRONTL_CONFIG_HPP__
#define __NEUTRONTL_CONFIG_HPP__

// 可选参数有：

// NEUTRONTL_CONFIG_NO_INFO 不包含Info.hpp
// NEUTRONTL_CONFIG_NO_DEBUG 不包含Debug.hpp与Debug.cpp
// NEUTRONTL_CONFIG_NO_INCLUDES 不包含Includes.hpp

// NEUTRONTL_CONFIG_USE_CHAR 不使用宽字符而使用单字节字符

// NEUTRONTL_CONFIG_NO_INLINE 禁止内联，否则对一些短小的函数使用内联以优化速度

// NEUTRONTL_CONFIG_SAFE 将完全不使用noexcept优化，即使它是空类（如BasicObject）

// NEUTRONTL_CONFIG_USE_ALIGN 将取消内存对齐，这可能会有一些问题
// NEUTRONTL_CONFIG_ALIGN_SIZE 内存对齐大小，默认为4，若没启用内存对齐，则为1

// NEUTRONTL_CONFIG_NO_CONSTEXPR 禁用常值表达式

// NEUTRONTL_CONFIG_NO_EXPLICIT 禁用explicit，也许会导致“模棱两可的xx”的错误

// 实现：

// 使用char
#ifdef NEUTRONTL_CONFIG_USE_CHAR
#warning Not using wide characters is not a good idea. It has not been tested.
/// @brief NTL字符
using NTL_CHAR = char;
#else
/// @brief NTL字符
using NTL_CHAR = wchar_t;
#endif

// 禁用内联
#ifdef NEUTRONTL_CONFIG_NO_INLINE
// 内联
#define NTL_INLINE
#else
// 内联
#define NTL_INLINE inline
#endif

// 禁用noexcept
#ifdef NEUTRONTL_CONFIG_SAFE
#warning There may be some more performance overhead.
// 无异常
#define NTL_NOEXCEPT
#else
// 无异常
#define NTL_NOEXCEPT noexcept
#endif

// 允许抛出异常
#define NTL_EXCEPT noexcept(false)

// 启用内存对齐
#ifdef NEUTRONTL_CONFIG_USE_ALIGN
#warning This may cause some problems.
#ifndef NEUTRONTL_CONFIG_ALIGN_SIZE
// 内存对齐大小
#define NEUTRONTL_CONFIG_ALIGN_SIZE 4
#endif
// 内存对齐
#define NTL_ALIGN alignas(NEUTRONTL_CONFIG_ALIGN_SIZE)
#else
#ifndef NEUTRONTL_CONFIG_ALIGN_SIZE
// 内存对齐大小
#define NEUTRONTL_CONFIG_ALIGN_SIZE 1
#endif
// 内存对齐
#define NTL_ALIGN alignas(1)
#endif

// 禁用常值表达式
#ifdef NEUTRONTL_CONFIG_NO_CONSTEXPR
// 常值表达式
#define NTL_CONSTEXPR
#else
// 常值表达式
#define NTL_CONSTEXPR constexpr
#endif

// 禁用explicit
#ifdef NEUTRONTL_CONFIG_NO_EXPLICIT
// 禁止隐式类型转换
#define NTL_EXPLICIT
#else
// 禁止隐式类型转换
#define NTL_EXPLICIT explicit
#endif

// 声明为虚函数
#define NTL_VIRTUAL virtual
// 覆写虚函数
#define NTL_OVERRIDE override
// 禁用虚函数覆写
#define NTL_FINAL final
// 纯虚函数声明
#define NTL_PURE_VIRTUAL 0

// 常值声明
#define NTL_CONST const
// 使用默认函数
#define NTL_DEFAULT default
// 删除此函数
#define NTL_DELETE delete

#endif