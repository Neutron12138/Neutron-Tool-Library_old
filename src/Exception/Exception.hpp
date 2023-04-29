#ifndef __NEUTRONTL_EXCEPTION_EXCEPTION_HPP__
#define __NEUTRONTL_EXCEPTION_EXCEPTION_HPP__

#include <string>
#include <exception>
#include <stdexcept>
#include "../Base/Object.hpp"
#include "../Base/Type.hpp"
#include "../Serialization/Serializable.hpp"
#include "../Serialization/Serialization.hpp"

#define NTL_MAKE_STATEMENT_INFO(function_name) \
    ntl::StringUtils::to_string(               \
        NTL_STRING("at file:\""),              \
        __FILE__,                              \
        NTL_STRING("\",function:\""),          \
        function_name,                         \
        NTL_STRING("\",line:"),                \
        __LINE__)

#define NTL_STATEMENT_INFO            \
    ntl::StringUtils::to_string(      \
        NTL_STRING("at file:\""),     \
        __FILE__,                     \
        NTL_STRING("\",function:\""), \
        __FUNCTION__,                 \
        NTL_STRING("\",line:"),       \
        __LINE__)

namespace ntl
{
    /// @brief 基础异常类
    class NTL_ALIGN Exception : public Serializable
    {
    public:
        using SelfType = Exception;
        using ParentType = Object;

    protected:
        /// @brief 异常说明
        String m_what;
        /// @brief 异常原因
        String m_why;
        /// @brief 异常位置
        String m_where;

    public:
        Exception() = default;
        explicit Exception(const std::exception &exception, const String &where);
        explicit Exception(const String &what, const String &why, const String &where);
        explicit Exception(const SelfType &from) = default;
        ~Exception() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        /// @brief 获取发生了什么异常
        /// @return 异常说明
        inline const String &what() const;

        /// @brief 获取为什么发生异常
        /// @return 异常原因
        inline const String &why() const;

        /// @brief 获取发生异常的位置在哪（在哪个文件，哪个函数）
        /// @return 异常位置
        inline const String &where() const;

    public:
        /// @brief 打印自身
        /// @param os 输出流
        virtual void print_self(OutputStream &os) const;

    public:
        Serialization serialize() override;
        Serialization serialize() const override;
        SelfType &deserialize(const Serialization &serialization) override;
    };

    OutputStream &operator<<(OutputStream &os, const Exception &exception);

} // namespace ntl

#endif