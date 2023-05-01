#ifndef __NEUTRONTL_SIGNAL_SLOT_HPP__
#define __NEUTRONTL_SIGNAL_SLOT_HPP__

#include "../Base/BasicObject.hpp"
#include "../Reflection/NonStaticMethod.hpp"

namespace ntl
{
    /// @brief 槽
    class NTL_ALIGN Slot : public BasicObject
    {
    public:
        using SelfType = Slot;
        using ParentType = BasicObject;

    protected:
        /// @brief 槽的对象
        void *m_object = nullptr;

        /// @brief 方法
        NonStaticMethod m_method;

    public:
        Slot() = default;
        Slot(void *object, const NonStaticMethod &method);
        Slot(const SelfType &from) = default;
        ~Slot() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        void *get_object() const;
        const NonStaticMethod &get_method() const;

    public:
        template <typename... ArgsType>
        void received(ArgsType &&...args) const;
    };

} // namespace ntl

#endif