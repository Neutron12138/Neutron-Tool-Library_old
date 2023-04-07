#ifndef __NEUTRONTL_CONFIG_HPP__
#define __NEUTRONTL_CONFIG_HPP__

// NTL类的说明符
// NTL_ALIGN 内存对齐

// 可选参数有：

// NEUTRONTL_CONFIG_NO_INFO 不包含Info.hpp
// NEUTRONTL_CONFIG_NO_DEBUG 不包含Debug.hpp与Debug.cpp
// NEUTRONTL_CONFIG_NO_INCLUDES 不包含Includes.hpp

// NEUTRONTL_CONFIG_USE_WCHAR 使用宽字节字符串而不是多字节字符串
// NEUTRONTL_CONFIG_USE_APPLICATION 使用NTL提供的Main入口

// 实现：

#ifdef NEUTRONTL_CONFIG_USE_WCHAR

#define NTL_CHAR(ch) L##ch
#define NTL_CSTRING(str) L##str
#define NTL_STRING(str) ntl::String(L##str)

#else

#define NTL_CHAR(ch) ch
#define NTL_CSTRING(str) str
#define NTL_STRING(str) ntl::String(str)

#endif

// 禁用内存对齐
#define NTL_ALIGN alignas(1)

#endif