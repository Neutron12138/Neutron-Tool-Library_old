#ifndef __NEUTRONTL_CONFIG_HPP__
#define __NEUTRONTL_CONFIG_HPP__

// NTL类的说明符
// NTL_ALIGN 内存对齐

// 可选参数有：

// NEUTRONTL_CONFIG_NO_INFO 不包含Info.hpp
// NEUTRONTL_CONFIG_NO_DEBUG 不包含Debug.hpp与Debug.cpp
// NEUTRONTL_CONFIG_NO_INCLUDES 不包含Includes.hpp

// NEUTRONTL_CONFIG_USE_WCHAR 使用宽字节字符串而不是多字节字符串

// 实现：

// 使用wchar
#ifdef NEUTRONTL_CONFIG_USE_WCHAR
/// @brief NTL字符
using NTL_CHAR = wchar_t;
#else
/// @brief NTL字符
using NTL_CHAR = char;
#endif

// 禁用内存对齐
#define NTL_ALIGN alignas(1)

#endif