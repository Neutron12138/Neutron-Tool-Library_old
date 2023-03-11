#ifndef __NEUTRONTL_SIGNAL_SIGNALABLE_CPP__
#define __NEUTRONTL_SIGNAL_SIGNALABLE_CPP__

#include "Signalable.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/CaughtException.hpp"

namespace ntl
{
    const typename Signalable::SignalMap &
    Signalable::get_signals() const
    {
        return m_signals;
    }

    bool
    Signalable::has_signal(
        const String &signal) const
    {
        return m_signals.find(signal) != m_signals.cend();
    }

    template <typename MethodType>
    void
    Signalable::connect(
        const String &signal,
        const String &name,
        void *object,
        MethodType method)
    {
        if (!has_signal(signal))
            throw unable_to_find_signal(
                signal,
                NTL_STRING("template <typename MethodType> void Signalable::connect(const String &signal,const String &name,void *object,MethodType method)"));

        m_signals.at(signal).connect(name, object, method);
    }

    void
    Signalable::connect(
        const String &signal,
        const String &name,
        const Slot &slot)
    {
        if (!has_signal(signal))
            throw unable_to_find_signal(
                signal,
                NTL_STRING("void Signalable::connect(const String &signal,const String &name,const Slot &slot)"));

        m_signals.at(signal).connect(name, slot);
    }

    void
    Signalable::disconnect(
        const String &signal,
        const String &name)
    {
        if (!has_signal(signal))
            throw unable_to_find_signal(
                signal,
                NTL_STRING("void Signalable::disconnect(const String &signal,const String &name)"));

        m_signals.at(signal).disconnect(name);
    }

    template <typename... ArgsType>
    void
    Signalable::emit(
        const String &signal,
        ArgsType &&...args) const
    {
        if (!has_signal(signal))
            throw unable_to_find_signal(
                signal,
                NTL_STRING("template <typename... ArgsType> void Signalable::emit(const String &signal,ArgsType &&...args) const"));

        try
        {
            m_signals.at(signal).emit(std::forward<ArgsType>(args)...);
        }
        catch (const CaughtException &exception)
        {
            throw CaughtException(
                exception,
                NTL_STRING("template <typename... ArgsType> void Signalable::emit(const String &signal,ArgsType &&...args) const"));
        }
        catch (const Exception &exception)
        {
            throw CaughtException(
                exception,
                NTL_STRING("template <typename... ArgsType> void Signalable::emit(const String &signal,ArgsType &&...args) const"));
        }
    }

    OutOfRangeException
    Signalable::unable_to_find_signal(
        const String &signal,
        const String &where)
    {
        return OutOfRangeException(
            StringUtils::to_string(
                NTL_STRING("Unable to find signal:\""),
                signal,
                NTL_STRING("\"")),
            where);
    }

} // namespace ntl

#endif