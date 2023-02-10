#ifndef __NEUTRONTL_SCRIPT_TYPE_HPP__
#define __NEUTRONTL_SCRIPT_TYPE_HPP__

#include <any>
#include <vector>
#include "../../Base/Object.hpp"
#include "../ScriptMisc.hpp"

namespace ntl
{
    namespace script
    {
        namespace Types
        {
            /// @brief 变量类型的特点
            class TypeTraits : public Object
            {
            public:
                using SelfType = TypeTraits;
                using ParentType = Object;

                /// @brief 运算符
                enum Operator
                {
                    /// @brief 加法
                    Addition = 0,

                    /// @brief 减法
                    Subtraction,

                    /// @brief 乘法
                    Multiplication,

                    /// @brief 除法
                    Division,

                    /// @brief 取余
                    MOD,

                    /// @brief 总数
                    Count,
                };

            public:
                constexpr TypeTraits() noexcept = default;
                constexpr explicit TypeTraits(const SelfType &from) noexcept = default;
                ~TypeTraits() override = default;

            public:
                constexpr SelfType &operator=(const SelfType &from) noexcept = default;

            public:
                /// @brief 默认构造函数
                /// @param memory 变量内存
                virtual void construction(MemoryPointer &memory) = 0;

                /// @brief 构造函数
                /// @param memory 变量内存
                /// @param arguments 参数列表
                virtual void construction(MemoryPointer &memory, const ArgumentsArray arguments) = 0;

                /// @brief 析构函数
                /// @param memory 变量内存
                /// @param arguments 参数列表
                virtual void destruction(MemoryPointer &memory) = 0;

                /// @brief 运算符
                /// @param memory 变量内存
                /// @param operation 运算符
                /// @param arguments 参数列表
                virtual void operation(MemoryPointer &memory, Operator operation, const ArgumentsArray arguments) = 0;

            public:
                /// @brief 检查内存大小是否合法
                /// @tparam TraitsType 类型特点类型
                /// @param memory 要检查的内存
                /// @return 内存大小是否合法
                template <typename TraitsType>
                static bool is_memory_size_legal(const MemoryPointer &memory);
            };
        } // namespace name

    } // namespace script

} // namespace ntl

#endif