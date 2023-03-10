#ifndef __NEUTRONTL_REFLECTION_DETAILS_HPP__
#define __NEUTRONTL_REFLECTION_DETAILS_HPP__

#include <map>
#include "../Base/Type.hpp"
#include "../Base/BasicObject.hpp"
#include "Field.hpp"
#include "Method.hpp"

namespace ntl
{
    class Reflectible;

    /// @brief 反射目标的细节
    class Details : public BasicObject
    {
    public:
        using SelfType = Details;
        using ParentType = BasicObject;

        /// @brief 属性列表
        using FieldMap = std::map<String, Field>;

        /// @brief 方法列表
        using MethodMap = std::map<String, Method>;

    protected:
        /// @brief 属性
        FieldMap m_fields;

        /// @brief 方法
        MethodMap m_methods;

        SizeT m_size;

    public:
        Details() = default;
        explicit Details(const FieldMap &fields, const MethodMap &methods, SizeT size);
        explicit Details(const SelfType &from) = default;
        ~Details() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const FieldMap &get_fields() const;

        const MethodMap &get_methods() const;

        SizeT get_size() const;

        bool has_field(const String &name) const;

        bool has_method(const String &name) const;

        /*public:
            template <typename ReturnType>
            ReturnType &get_field(const String &name) const;

            template <typename ReturnType, typename... ArgsType>
            ReturnType call_method(const String &name, ArgsType &&...args) const;*/
    };

} // namespace ntl

#endif