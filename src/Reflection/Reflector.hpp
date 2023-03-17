#ifndef __NEUTRONTL_REFLECTION_REFLECTOR_HPP__
#define __NEUTRONTL_REFLECTION_REFLECTOR_HPP__

#include "../Base/Object.hpp"
#include "../Memory/SharedPointer.hpp"
#include "Details.hpp"

namespace ntl
{
    /// @brief 反射器
    class NTL_ALIGN Reflector : public Object
    {
    public:
        using SelfType = Reflector;
        using ParentType = Object;

        /// @brief 类细节指针
        using DetailsPointer = SharedPointer<Details>;

        /// @brief 类列表
        using ClassMap = std::map<String, DetailsPointer>;

    protected:
        /// @brief 类
        ClassMap m_classes;

    public:
        Reflector() = default;
        explicit Reflector(const SelfType &from) = default;
        ~Reflector() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        template <typename ClassType>
        const DetailsPointer &register_class(const String &name);
        const DetailsPointer &register_class(const String &name, const Details &details);
        const DetailsPointer &register_class(const String &name, const DetailsPointer &details);

        const DetailsPointer &get_class(const String &name) const;

        bool has_class(const String &name) const;
    };

} // namespace ntl

#endif