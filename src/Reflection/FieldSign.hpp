#ifndef __NEUTRONTL_REFLECTION_FIELDSIGN_HPP__
#define __NEUTRONTL_REFLECTION_FIELDSIGN_HPP__

#include "../Base/BasicObject.hpp"
#include "../TypeInfo/Type.hpp"

namespace ntl
{
    /// @brief 属性签名
    class NTL_ALIGN FieldSign : public BasicObject
    {
    public:
        using SelfType = FieldSign;
        using ParentType = BasicObject;

    protected:
        /// @breif 属性类型
        Type m_field_type;

    public:
        explicit FieldSign(const Type &field_sign);
        explicit FieldSign(const SelfType &from) = default;
        ~FieldSign() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const Type &get_field_type() const;

        template <typename T>
        bool check() const;
    };

} // namespace ntl

#endif