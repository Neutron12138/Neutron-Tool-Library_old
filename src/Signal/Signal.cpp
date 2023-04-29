#ifndef __NEUTRONTL_SIGNAL_SIGNAL_CPP__
#define __NEUTRONTL_SIGNAL_SIGNAL_CPP__

#include "Signal.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/InvalidArgumentException.hpp"
#include "../Exception/CaughtException.hpp"

namespace ntl
{
    Signal::Signal(
        SizeT args_count)
        : m_args_count(args_count) {}

    const typename Signal::SlotContainer &
    Signal::get_slots() const
    {
        return m_slots;
    }

    SizeT
    Signal::get_args_count() const
    {
        return m_args_count;
    }

    bool
    Signal::has_slot(
        const String &name) const
    {
        return m_slots.find(name) != m_slots.cend();
    }

    template <typename MethodType>
    void
    Signal::connect(
        const String &name,
        void *object,
        MethodType method)
    {
        connect(
            name,
            Slot(
                object,
                NonStaticMethod(
                    method,
                    m_args_count)));
    }

    void
    Signal::connect(
        const String &name,
        const Slot &slot)
    {
        if (slot.get_method().get_args_count() != m_args_count)
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("The number of arguments of the method ("),
                    slot.get_method().get_args_count(),
                    NTL_STRING(") is different from the required number of parameters ("),
                    m_args_count,
                    NTL_STRING(")")),
                NTL_MAKE_STATEMENT_INFO("void Signal::connect(const String &name,const Slot &slot)"));

        m_slots.insert(
            Signal::SlotContainer::value_type(
                name,
                slot));
    }

    void
    Signal::disconnect(
        const String &name)
    {
        if (!has_slot(name))
            throw OutOfRangeException(
                StringUtils::to_string(
                    NTL_STRING("Unable to find slot: \""),
                    name,
                    NTL_STRING("\"")),
                NTL_MAKE_STATEMENT_INFO("void Signal::disconnect(const String &name)"));

        m_slots.erase(m_slots.find(name));
    }

    template <typename... ArgsType>
    void
    Signal::emit(
        ArgsType &&...args) const
    {
        try
        {
            for (auto iter = m_slots.cbegin(); iter != m_slots.cend(); iter++)
                iter->second.received(std::forward<ArgsType>(args)...);
        }
        catch (const CaughtException &exception)
        {
            throw CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("template <typename... ArgsType> void Signal::emit(ArgsType &&...args) const"));
        }
        catch (const Exception &exception)
        {
            throw CaughtException(
                exception,
                NTL_MAKE_STATEMENT_INFO("template <typename... ArgsType> void Signal::emit(ArgsType &&...args) const"));
        }
    }

} // namespace ntl

#endif