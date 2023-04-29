#ifndef __NEUTRONTL_SIGNAL_SIGNALABLE_HPP__
#define __NEUTRONTL_SIGNAL_SIGNALABLE_HPP__

#include <map>
#include "../Reflection/Reflectible.hpp"
#include "Signal.hpp"
#include "../Exception/OutOfRangeException.hpp"

namespace ntl
{
    /// @brief 可发送/接收信号的对象
    class NTL_ALIGN Signalable : public Reflectible
    {
    public:
        using SelfType = Signalable;
        using ParentType = Reflectible;

        /// @brief 信号列表
        using SignalMap = std::map<String, Signal>;

    protected:
        /// @brief 信号列表
        SignalMap m_signals;

    public:
        Signalable() = default;
        explicit Signalable(const SelfType &from) = default;
        ~Signalable() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const SignalMap &get_signals() const;

        bool has_signal(const String &signal) const;

    public:
        template <typename MethodType>
        void connect(const String &signal, const String &name, void *object, MethodType method);
        void connect(const String &signal, const String &name, const Slot &slot);

        void disconnect(const String &signal, const String &name);

        template <typename... ArgsType>
        void emit(const String &signal, ArgsType &&...args) const;

    public:
        static OutOfRangeException unable_to_find_signal(const String &signal, const String &where);
    };

} // namespace ntl

#endif