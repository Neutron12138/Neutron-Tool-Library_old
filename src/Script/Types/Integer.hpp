#ifndef __NEUTRONTL_SCRIPT_INTEGER_HPP__
#define __NEUTRONTL_SCRIPT_INTEGER_HPP__

#include "TypeTraits.hpp"

namespace ntl
{
    namespace script
    {
        namespace Types
        {
            /// @brief 整数类型
            class Integer : public TypeTraits
            {
            public:
                using SelfType = Integer;
                using ParentType = TypeTraits;

                /// @brief 内部类型
                using InternalType = Int64;
                /// @brief 类型大小
                static constexpr SizeT TYPE_SIZE = sizeof(InternalType);

            public:
                constexpr Integer() noexcept = default;
                constexpr explicit Integer(const SelfType &from) noexcept = default;
                ~Integer() override = default;

            public:
                constexpr SelfType &operator=(const SelfType &from) noexcept = default;

            public:
                void construction(MemoryPointer &memory) override;
                void construction(MemoryPointer &memory, const ArgumentsArray arguments) override;
                void destruction(MemoryPointer &memory) override;
                void operation(MemoryPointer &memory, Operator operation, const ArgumentsArray arguments) override;

            public:
                /// @brief 转换为内部类型
                /// @param memory 内存
                /// @return 内部类型
                static InternalType &as_internal_type(const MemoryPointer &memory);
            };

        } // namespace Types

    } // namespace script

} // namespace ntl

#endif