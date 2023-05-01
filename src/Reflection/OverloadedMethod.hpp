#ifndef __NEUTRONTL_REFLECTION_OVERLOADEDMETHOD_HPP__
#define __NEUTRONTL_REFLECTION_OVERLOADEDMETHOD_HPP__

#include <map>
#include "../Base/BasicObject.hpp"

namespace ntl
{
    /// @brief 重载方法
    /// @tparam m_MethodClassType 方法类型，可以为NonStaticMethod或StaticMethod
    template <typename m_MethodClassType>
    class NTL_ALIGN OverloadedMethod : public BasicObject
    {
    public:
        using MethodClassType = m_MethodClassType;
        using MethodContainer = std::map<String, MethodClassType>;

    protected:
    };

} // namespace ntl

#endif