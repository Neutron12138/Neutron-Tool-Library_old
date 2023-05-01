#ifndef __NEUTRONTL_SIGNAL_SIGNAL_HPP__
#define __NEUTRONTL_SIGNAL_SIGNAL_HPP__

#include <map>
#include "../Base/BasicObject.hpp"
#include "Slot.hpp"

namespace ntl
{
    /// @brief 信号
    class NTL_ALIGN Signal : public BasicObject
    {
    public:
        using SelfType = Signal;
        using ParentType = BasicObject;

        /// @brief 槽容器
        using SlotContainer = std::map<String, Slot>;

    protected:
        /// @brief 槽
        SlotContainer m_slots;

        /// @brief 参数总数
        SizeT m_args_count = 0;

    public:
        Signal() = default;
        Signal(SizeT args_count);
        Signal(const SelfType &from) = default;
        ~Signal() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const SlotContainer &get_slots() const;
        SizeT get_args_count() const;

        bool has_slot(const String &name) const;

    public:
        template <typename MethodType>
        void connect(const String &name, void *object, MethodType method);
        void connect(const String &name, const Slot &slot);

        void disconnect(const String &name);

        template <typename... ArgsType>
        void emit(ArgsType &&...args) const;
    };

} // namespace ntl

#endif