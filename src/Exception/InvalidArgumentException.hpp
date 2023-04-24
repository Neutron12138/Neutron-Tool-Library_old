#ifndef __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_INVALIDARGUMENTEXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 无效参数异常
    class NTL_ALIGN InvalidArgumentException : public Exception
    {
    public:
        using SelfType = InvalidArgumentException;
        using ParentType = Exception;

    public:
        InvalidArgumentException() = default;
        explicit InvalidArgumentException(const String &why, const String &where);
        explicit InvalidArgumentException(const SelfType &from) = default;
        ~InvalidArgumentException() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif
