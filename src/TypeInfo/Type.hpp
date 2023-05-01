#ifndef __NEUTRONTL_TYPEINFO_TYPE_HPP__
#define __NEUTRONTL_TYPEINFO_TYPE_HPP__

#include <typeinfo>
#include "../Base/BasicObject.hpp"
#include "../Base/Type.hpp"

namespace ntl
{
    /// @brief 类型
    class NTL_ALIGN Type : public BasicObject
    {
    public:
        using SelfType = Type;
        using ParentType = BasicObject;

    protected:
        /// @brief 名称
        String m_name;

        /// @brief 类型信息
        const std::type_info &m_info;

    public:
        Type(const std::type_info &info);
        Type(const String &name, const std::type_info &info);
        Type(const SelfType &from) = default;
        ~Type() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        bool operator==(const SelfType &another) const;
        bool operator!=(const SelfType &another) const;

    public:
        /// @brief 获取名称
        /// @return 名称
        const String &get_name() const;

        /// @brief 获取类型信息
        /// @return 类型信息
        const std::type_info &get_info() const;

        /// @brief 检查名称是否相同
        /// @param another 另一个
        /// @return 名称是否相同
        bool is_name_equal(const SelfType &another) const;

        /// @brief 检查类型信息是否相同
        /// @param another 另一个
        /// @return 类型信息是否相同
        bool is_info_equal(const SelfType &another) const;
    };

    /// @brief 获取类型
    /// @tparam T 类型
    /// @param name 类型名
    /// @return 类型
    template <typename T>
    Type get_type(const String &name);

    /// @brief 获取类型
    /// @tparam T 类型
    /// @return 类型
    template <typename T>
    Type get_type();

    /// @brief 获取类型
    /// @tparam T 类型
    /// @param name 类型名
    /// @return 类型
    template <typename T>
    Type get_type(const String &name, const T &);

    /// @brief 获取类型
    /// @tparam T 类型
    /// @return 类型
    template <typename T>
    Type get_type(const T &);

} // namespace ntl

#endif