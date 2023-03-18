#ifndef __NEUTRONTL_REFLECTION_METHODSIGN_CPP__
#define __NEUTRONTL_REFLECTION_METHODSIGN_CPP__

#include "MethodSign.hpp"
#include "../Exception/TypeErrorException.hpp"
#include "../String/StringUtils.hpp"
#include "../Misc/ContainerOperation.hpp"

namespace ntl
{
    MethodSign::MethodSign(
        const Type &return_type,
        const std::vector<Type> &args_type)
        : m_return_type(return_type),
          m_args_type(args_type) {}

    const Type &
    MethodSign::get_return_type() const
    {
        return m_return_type;
    }

    const std::vector<Type> &
    MethodSign::get_args_type() const
    {
        return m_args_type;
    }

    template <typename ArgType>
    std::vector<Type>
    MethodSign::get_args_type(
        const ArgType &arg) const
    {
        return std::vector<Type>{get_type<ArgType>()};
    }

    template <typename ArgType, typename... ArgsType>
    std::vector<Type>
    MethodSign::get_args_type(
        const ArgType &arg,
        const ArgsType &...args) const
    {
        return ContainerOperation::merge(
            get_args_type(arg),
            get_args_type(args...));
    }

    template <typename... ArgsType>
    bool
    MethodSign::check_args(const ArgsType &...args)
    {
        std::vector<Type> result = get_args_type(args...);

        for (SizeT i = 0; i < result.size(); i++)
            if (result.at(i) != m_args_type.at(i))
                throw TypeErrorException(
                    StringUtils::to_string(
                        NTL_STRING("The type of the argument (at:"),
                        i,
                        NTL_STRING(") is \""),
                        result.at(i),
                        NTL_STRING("\", but the type is \""),
                        m_args_type.at(i).get_info().name(),
                        NTL_STRING("\"")),
                    NTL_STRING("template <typename ArgType> bool MethodSign::check_arg(SizeT index) const"));

        return true;
    }

    template <typename T>
    bool
    MethodSign::check_return() const
    {
        return get_type<T>() == m_return_type;
    }

    template <typename ReturnType, typename... ArgsType>
    bool
    MethodSign::check() const
    {
        return check_return<ReturnType>() &&
               check_args<0, ArgsType...>();
    }

} // namespace ntl

#endif