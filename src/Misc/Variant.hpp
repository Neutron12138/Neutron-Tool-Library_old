#ifndef __NEUTRONTL_MISC_VARIANT_HPP__
#define __NEUTRONTL_MISC_VARIANT_HPP__

#include <vector>
#include <variant>
#include "../Base/Object.hpp"
#include "../Memory/UniquePointer.hpp"
#include "../Memory/SharedPointer.hpp"
#include "../Memory/WeakPointer.hpp"

// 自动格式化得有点问题...

// Variant的类型列表
#define NEUTRONTL_VARIANT_TYPES   \
    CharW,                        \
        Byte,                     \
        UByte,                    \
        Short,                    \
        UShort,                   \
        Int,                      \
        UInt,                     \
        Long,                     \
        ULong,                    \
        LLong,                    \
        ULLong,                   \
        Float,                    \
        Double,                   \
        UniversalPointer,         \
                                  \
        String,                   \
                                  \
        WeakPointer<BasicObject>, \
        WeakPointer<Object>,      \
                                  \
        std::vector<Variant>,     \
                                  \
        SharedPointer<Variant>,   \
        UniquePointer<Variant>,   \
        WeakPointer<Variant>

namespace ntl
{
    struct Variant;

    /// @brief 变体类型
    class Variant
        : public Object,
          public std::variant<NEUTRONTL_VARIANT_TYPES>
    {
    public:
        using SelfType = Variant;
        using ParentType = std::variant<NEUTRONTL_VARIANT_TYPES>;

    public:
        Variant() = default;
        template <typename ValueType>
        Variant(const ValueType &value);
        Variant(const SelfType &from) = default;
        ~Variant() override = default;

    public:
        using ParentType::operator=;
        SelfType &operator=(const SelfType &from) = default;

        template <typename ValueType>
        operator ValueType() const;
    };

} // namespace ntl

#endif
