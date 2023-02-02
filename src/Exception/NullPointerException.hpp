#ifndef __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_NULLPOINTEREXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 空指针异常
    class NTL_ALIGN NullPointerException : public Exception
    {
    public:
        using SelfType = NullPointerException;
        using ParentType = Exception;

    public:
        NullPointerException() = default;
        NTL_EXPLICIT NullPointerException(const String &where);
        NTL_EXPLICIT NullPointerException(const NullPointerException &from) = default;
        ~NullPointerException() NTL_OVERRIDE = default;

    public:
        NullPointerException &operator=(const NullPointerException &from) = default;
    };

} // namespace ntl

#endif