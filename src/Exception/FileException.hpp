#ifndef __NEUTRONTL_EXCEPTION_FILEEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_FILEEXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 文件未找到异常
    class NTL_ALIGN FileException : public Exception
    {
    public:
        using SelfType = FileException;
        using ParentType = Exception;

    public:
        FileException() = default;
        FileException(const String &why, const String &where);
        FileException(const SelfType &from) = default;
        ~FileException() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif
