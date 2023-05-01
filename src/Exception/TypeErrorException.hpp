#ifndef __NEUTRONTL_EXCEPTION_TYPEERROREXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_TYPEERROREXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 类型错误异常
    class NTL_ALIGN TypeErrorException : public Exception
    {
    public:
        using SelfType = TypeErrorException;
        using ParentType = Exception;

    public:
        TypeErrorException() = default;
        TypeErrorException(const String &why, const String &where);
        TypeErrorException(const SelfType &from) = default;
        ~TypeErrorException() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif