#ifndef __NEUTRONTL_DEBUG_CPP__
#define __NEUTRONTL_DEBUG_CPP__

#include "Debug.hpp"

#ifdef NEUTRONTL_DEBUG

namespace __ntl__
{
    __Debugger__ &__Debugger__::get()
    {
        static __Debugger__ debugger;
        return debugger;
    }

    void __Debugger__::set_output_func(const std::function<void(const wchar_t *)> &output_func)
    {
        m_output_func = output_func;
    }

    const std::function<void(const wchar_t *)> &__Debugger__::get_output_func() const
    {
        return m_output_func;
    }

    void __Debugger__::output(const wchar_t *str)
    {
        m_output_func(str);
    }
} // namespace __ntl__

#endif

#endif