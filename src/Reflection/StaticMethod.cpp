#ifndef __NEUTRONTL_REFLECTION_STATICMETHOD_CPP__
#define __NEUTRONTL_REFLECTION_STATICMETHOD_CPP__

#include <iostream>
#include "StaticMethod.hpp"
#include "../Exception/InvalidArgumentException.hpp"
#include "../String/StringUtils.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename MethodType>
    StaticMethod::StaticMethod(
        MethodType pointer,
        SizeT args_count)
        : Method(
              pointer,
              args_count) {}

    template <typename ReturnType, typename... ArgsType>
    ReturnType
    StaticMethod::call(
        ArgsType &&...args) const
    {
        if (m_pointer == nullptr)
            throw NullPointerException(
                NTL_STRING("template <typename ReturnType, typename... ArgsType> ReturnType StaticMethod::call(ArgsType &&...args) const"));

        const SizeT args_count = sizeof...(args);
        if (args_count != m_args_count)
            throw InvalidArgumentException(
                StringUtils::to_string(
                    NTL_STRING("The number of parameters is wrong, "),
                    m_args_count,
                    NTL_STRING(" are required, but "),
                    args_count,
                    NTL_STRING(" are provided")),
                NTL_STRING("template <typename ReturnType, typename... ArgsType> ReturnType StaticMethod::call(ArgsType &&...args) const"));

        using MethodType = ReturnType (*)(ArgsType...);
        return (*reinterpret_cast<MethodType>(m_pointer))(
            std::forward<ArgsType>(args)...);
    }

} // namespace ntl

#endif