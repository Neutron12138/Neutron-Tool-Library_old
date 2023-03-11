#ifndef __NEUTRONTL_SIGNAL_SLOT_CPP__
#define __NEUTRONTL_SIGNAL_SLOT_CPP__

#include "Slot.hpp"
#include "../Exception/CaughtException.hpp"

namespace ntl
{
    Slot::Slot(
        void *object,
        const NonStaticMethod &method)
        : m_object(object),
          m_method(method) {}

    void *
    Slot::get_object() const
    {
        return m_object;
    }

    const NonStaticMethod &
    Slot::get_method() const
    {
        return m_method;
    }

    template <typename... ArgsType>
    void
    Slot::received(
        ArgsType &&...args) const
    {
        try
        {
            m_method.call<void>(m_object, std::forward<ArgsType>(args)...);
        }
        catch (const CaughtException &exception)
        {
            throw CaughtException(
                exception,
                NTL_STRING("template <typename... ArgsType> void Slot::received(ArgsType &&...args) const"));
        }
        catch (const Exception &exception)
        {
            throw CaughtException(
                exception,
                NTL_STRING("template <typename... ArgsType> void Slot::received(ArgsType &&...args) const"));
        }
    }

} // namespace ntl

#endif