#ifndef __NEUTRONTL_REFLECTION_INSTANCE_HPP__
#define __NEUTRONTL_REFLECTION_INSTANCE_HPP__

#include <vector>
#include "../Base/Type.hpp"
#include "../Memory/SharedPointer.hpp"
#include "Details.hpp"

namespace ntl
{
    /// @brief 实例
    class Instance : public Object
    {
    public:
        using SelfType = Instance;
        using ParentType = Object;

        using DetailsPointer = SharedPointer<Details>;
        using Memory = std::vector<Byte>;

    protected:
        DetailsPointer m_details;
        Memory m_memory;

    public:
        Instance() = default;
        explicit Instance(const DetailsPointer &details, const Memory &memory);
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