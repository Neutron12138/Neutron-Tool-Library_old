#ifndef __NEUTRONTL_EXCEPTION_FILENOTFOUNDEXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_FILENOTFOUNDEXCEPTION_HPP__

#include "Exception.hpp"

namespace ntl
{
    /// @brief 文件未找到异常
    class NTL_ALIGN FileNotFoundException : public Exception
    {
    public:
        using SelfType = FileNotFoundException;
        using ParentType = Exception;

    public:
        FileNotFoundException() = default;
        FileNotFoundException(const String &why, const String &where);
        FileNotFoundException(const SelfType &from) = default;
        ~FileNotFoundException() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace ntl

#endif
