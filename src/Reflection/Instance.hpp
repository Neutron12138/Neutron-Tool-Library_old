#ifndef __NEUTRONTL_REFLECTION_INSTANCE_HPP__
#define __NEUTRONTL_REFLECTION_INSTANCE_HPP__

#include <vector>
#include "../Base/Type.hpp"
#include "../Base/Object.hpp"
#include "Reflector.hpp"

namespace ntl
{
    /// @brief 实例
    class NTL_ALIGN Instance : public Object
    {
    public:
        using SelfType = Instance;
        using ParentType = Object;

    protected:
        typename Reflector::DetailsPointer m_details;
        SharedPointer<Byte> m_memory;

    public:
        Instance() = default;
        explicit Instance(const typename Reflector::DetailsPointer &details, const SharedPointer<Byte> &memory);
        explicit Instance(const SelfType &from) = default;
        ~Instance() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        template <typename... ArgsType>
        void construct(ArgsType &&...args);
    };

} // namespace ntl

#endif