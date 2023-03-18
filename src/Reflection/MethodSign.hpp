#ifndef __NEUTRONTL_REFLECTION_METHODSIGN_HPP__
#define __NEUTRONTL_REFLECTION_METHODSIGN_HPP__

#include <vector>
#include "../Base/BasicObject.hpp"
#include "../TypeInfo/Type.hpp"

namespace ntl
{
    /// @brief 方法签名
    class NTL_ALIGN MethodSign : public BasicObject
    {
    public:
        using SelfType = MethodSign;
        using ParentType = BasicObject;

    protected:
        /// @brief 返回值类型
        Type m_return_type;

        /// @brief 参数类型
        std::vector<Type> m_args_type;

    public:
        MethodSign(const Type &return_type, const std::vector<Type> &args_type);
        explicit MethodSign(const SelfType &from) = default;
        ~MethodSign() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const Type &get_return_type() const;

        const std::vector<Type> &get_args_type() const;

        template <typename ArgType>
        std::vector<Type> get_args_type(const ArgType &arg) const;

        template <typename ArgType, typename... ArgsType>
        std::vector<Type> get_args_type(const ArgType &arg, const ArgsType &...args) const;

        template <typename... ArgsType>
        bool check_args(const ArgsType &...args);

        template <typename T>
        bool check_return() const;

        template <typename ReturnType, typename... ArgsType>
        bool check() const;
    };

} // namespace ntl

#endif