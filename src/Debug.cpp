#ifndef __NEUTRONTL_DEBUG_CPP__
#define __NEUTRONTL_DEBUG_CPP__

#include "Debug.hpp"

#ifndef NEUTRONTL_CONFIG_NO_DEBUG

namespace __ntl__
{
    template <typename FuncType>
    void
    set_debug_output_func(
        FuncType func)
    {
        debug_output_func = func;
    }

    template <typename... ArgsType>
    void
    debug_output(
        ArgsType &&...args)
    {
        if (debug_output_func)
            debug_output_func(
                ntl::StringUtils::to_string(
                    std::forward<ArgsType>(args)...)
                    .data());
    }

} // namespace __ntl__

#endif

#endif
