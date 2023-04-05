#ifndef __NEUTRONTL_SERIALIZATION_SERIALIZATION_HPP__
#define __NEUTRONTL_SERIALIZATION_SERIALIZATION_HPP__

#include "../Base/Object.hpp"
#include "Serializable.hpp"

namespace ntl
{
    /// @brief 序列
    class NTL_ALIGN Serialization : public Object
    {
    public:
        using SelfType = Serialization;
        using ParentType = Object;

    protected:
        /// @brief 序列
        String m_serialization;

    public:
        Serialization() = default;
        explicit Serialization(const String &serialization);
        explicit Serialization(const SelfType &from) = default;
        ~Serialization() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        bool operator>(const SelfType &another);
        bool operator<(const SelfType &another);
        bool operator>=(const SelfType &another);
        bool operator<=(const SelfType &another);
        bool operator==(const SelfType &another);
        bool operator!=(const SelfType &another);
        operator String();
        operator String() const;

    public:
        /// @brief 获取序列
        /// @return 序列
        const ntl::String &get_serialization() const;

        /// @brief 设置序列
        /// @param serialization 序列
        /// @return 本对象
        SelfType &set_serialization(const ntl::String &serialization);
    };

    OutputStream &operator<<(OutputStream &os, const Serialization &serialization);

} // namespace ntl

#endif