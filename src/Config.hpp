#ifndef __NEUTRONTL_CONFIG_HPP__
#define __NEUTRONTL_CONFIG_HPP__

// 可选参数有：

// NEUTRONTL_CONFIG_NO_INFO 不包含Info.hpp
// NEUTRONTL_CONFIG_NO_DEBUG 不包含Debug.hpp与Debug.cpp
// NEUTRONTL_CONFIG_NO_INCLUDES 不包含Includes.hpp

// NEUTRONTL_CONFIG_USE_CHAR 不使用宽字符而使用单字节字符

// NEUTRONTL_CONFIG_USE_INLINE 使用内联代替一些重复出现的部分

// NEUTRONTL_CONFIG_SAFE 将完全不使用noexcept优化，即使它是空类（如BasicObject）

// NEUTRONTL_CONFIG_USE_ALIGN 将取消内存对齐，这可能会有一些问题
// NEUTRONTL_CONFIG_ALIGN_SIZE 内存对齐大小，默认为4，若没启用内存对齐，则为1

// NEUTRONTL_CONFIG_CONSTEXPR_NO 禁用常值表达式

#ifdef NEUTRONTL_CONFIG_USE_CHAR
#warning Not using wide characters is not a good idea. It has not been tested.
/// @brief NTL字符
using NTL_CHAR = char;
// #define NTL_CHAR char
#else
/// @brief NTL字符
using NTL_CHAR = wchar_t;
// #define NTL_CHAR wchar_t
#endif

#ifdef NEUTRONTL_CONFIG_USE_INLINE
#warning Not sure whether the program is completely free of problems, and may make the final program bloated.
#define NTL_INLINE inline
#else
#define NTL_INLINE
#endif

#ifdef NEUTRONTL_CONFIG_SAFE
#warning There may be some more performance overhead.
#define NTL_NOEXCEPT
#else
#define NTL_NOEXCEPT noexcept
#endif

#ifdef NEUTRONTL_CONFIG_USE_ALIGN
#warning This may cause some problems.
#ifndef NEUTRONTL_CONFIG_ALIGN_SIZE
#define NEUTRONTL_CONFIG_ALIGN_SIZE 4
#endif
#define NTL_ALIGN alignas(NEUTRONTL_CONFIG_ALIGN_SIZE)
#else
#ifndef NEUTRONTL_CONFIG_ALIGN_SIZE
#define NEUTRONTL_CONFIG_ALIGN_SIZE 1
#endif
#define NTL_ALIGN alignas(1)
#endif

#ifdef NEUTRONTL_CONFIG_CONSTEXPR_NO
#define NTL_CONSTEXPR
#else
#define NTL_CONSTEXPR constexpr
#endif

#endif