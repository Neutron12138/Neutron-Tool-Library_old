#ifndef __NEUTRONTL_MACROS_HPP__
#define __NEUTRONTL_MACROS_HPP__

// 起提示作用，表示输入
#define __in__
// 起提示作用，表示引用
#define __ref__
// 起提示作用，表示输出
#define __out__

// 没有什么用的宏定义
/*
#define _in_(x) x const&
#define _ref_(x) x&
#define _out_(x) x&
*/

// NTL命名空间
namespace NTL_NAMESPACE = ntl;
// #define NTL_NAMESPACE ntl

#endif