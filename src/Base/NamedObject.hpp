#ifndef __NEUTRONTL_BASE_NAMEDOBJECT_HPP__
#define __NEUTRONTL_BASE_NAMEDOBJECT_HPP__

#include "Object.hpp"
#include "Type.hpp"

namespace ntl
{
    /// @brief 可命名的对象，可以赋予其名字
    class NTL_ALIGN NamedObject : public Object
    {
    public:
        using SelfType = NamedObject;
        using ParentType = Object;

    protected:
        /// @brief 本对象的名称
        String m_name;

    public:
        NTL_INLINE NamedObject() = default;
        NTL_INLINE NamedObject(const String &name);
        NTL_INLINE NamedObject(const SelfType &from) = default;
        NTL_INLINE ~NamedObject() = default;

    public:
        NTL_INLINE SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取本对象的名称
        /// @return 本对象的名称
        NTL_INLINE const String &get_name() const;

        /// @brief 设置本对象的名称，如果要禁用，可以覆写为空（什么都不执行）
        /// @param name 本对象的名称
        NTL_INLINE virtual void set_name(const String &name);
    };
} // namespace ntl

#endif