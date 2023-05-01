#ifndef __NEUTRONTL_REFLECTION_DETAILS_HPP__
#define __NEUTRONTL_REFLECTION_DETAILS_HPP__

#include <map>
#include "../Base/Type.hpp"
#include "../Base/BasicObject.hpp"
#include "NonStaticField.hpp"
#include "StaticField.hpp"
#include "NonStaticMethod.hpp"
#include "StaticMethod.hpp"

namespace ntl
{
    class Reflectible;

    /// @brief 反射目标的细节
    class NTL_ALIGN Details : public BasicObject
    {
    public:
        using SelfType = Details;
        using ParentType = BasicObject;

        /// @brief 成员列表
        /// @tparam MemberType
        template <typename MemberType>
        using MemberMap = std::map<String, MemberType>;

        /// @brief 非静态属性列表
        using NonStaticFieldMap = MemberMap<NonStaticField>;

        /// @brief 非静态方法列表
        using NonStaticMethodMap = MemberMap<NonStaticMethod>;

        /// @brief 静态属性列表
        using StaticFieldMap = MemberMap<StaticField>;

        /// @brief 静态方法列表
        using StaticMethodMap = MemberMap<StaticMethod>;

        /// @brief 获取反射细节的函数的函数名
        static String get_reflection_details_name;

        /// @brief 构造函数的函数名
        static String construction_name;

        /// @brief 析构函数的函数名
        static String destruction_name;

    protected:
        /// @brief 类的大小
        SizeT m_size;

        /// @brief 非静态属性
        NonStaticFieldMap m_nonstatic_fields;

        /// @brief 静态属性
        StaticFieldMap m_static_fields;

        /// @brief 非静态方法
        NonStaticMethodMap m_nonstatic_methods;

        /// @brief 静态方法
        StaticMethodMap m_static_methods;

    public:
        Details() = default;
        Details(SizeT size);
        Details(
            SizeT size,
            const NonStaticFieldMap &nonstatic_fields,
            const StaticFieldMap &static_fields,
            const NonStaticMethodMap &nonstatic_methods,
            const StaticMethodMap &static_methods);
        Details(const SelfType &from) = default;
        ~Details() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        SizeT get_size() const;
        const NonStaticFieldMap &get_nonstatic_fields() const;
        const StaticFieldMap &get_static_fields() const;
        const NonStaticMethodMap &get_nonstatic_methods() const;
        const StaticMethodMap &get_static_methods() const;

    public:
        bool has_field(const String &name) const;
        bool has_method(const String &name) const;

    public:
        Details merge(const Details &another);
        template <typename... DetailsType>
        Details merge(const Details &another, const DetailsType &...others);

        /*public:
            template <typename ReturnType>
            ReturnType &get_field(const String &name) const;

            template <typename ReturnType, typename... ArgsType>
            ReturnType call_method(const String &name, ArgsType &&...args) const;*/
    };

} // namespace ntl

#endif