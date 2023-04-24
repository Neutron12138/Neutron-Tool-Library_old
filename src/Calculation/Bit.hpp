#ifndef __NEUTRONTL_CALCULATION_BIT_HPP__
#define __NEUTRONTL_CALCULATION_BIT_HPP__

#include "../Base/BasicObject.hpp"
#include "../Base/Type.hpp"

namespace ntl
{
    template <SizeT m_numeration, typename m_StorageType = Byte>
    class Bit : public BasicObject
    {
    public:
        using StorageType = m_StorageType;

        using SelfType = Bit<m_numeration, StorageType>;
        using ParentType = BasicObject;

    public:
        StorageType value;

    public:
        Bit() = default;
        explicit Bit(const StorageType &v);
        explicit Bit(const SelfType &from) = default;
        ~Bit() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

        bool operator==(const SelfType &another) const;
        bool operator!=(const SelfType &another) const;

    public:
        /// @brief 与另一个数相加
        /// @param another 另一个数
        /// @return 是否需要进位
        bool add(const SelfType &another);

        /// @brief 与另一个数相减
        /// @param another 另一个数
        /// @return 是否需要借位
        bool sub(const SelfType &another);

        /// @brief 与另一个数相乘
        /// @param another 另一个数
        /// @return 进位值
        SelfType mul(const SelfType &another);

        /// @brief 与另一个数相除
        /// @param another 另一个数
        /// @return 余数
        SelfType div(const SelfType &another);

        /// @brief 与另一个数相加
        /// @param another 另一个数
        /// @return
        SelfType add(const SelfType &another, bool &) const;

        /// @brief 与另一个数相减
        /// @param another 另一个数
        /// @return
        SelfType sub(const SelfType &another, bool &) const;

        /// @brief 与另一个数相乘
        /// @param another 另一个数
        /// @return
        SelfType mul(const SelfType &another, SelfType &) const;

        /// @brief 与另一个数相除
        /// @param another 另一个数
        /// @return
        SelfType div(const SelfType &another, SelfType &) const;
    };

} // namespace ntl

#endif
