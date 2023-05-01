#ifndef __NEUTRONTL_RESOURCE_RESOURCEDELETER_HPP__
#define __NEUTRONTL_RESOURCE_RESOURCEDELETER_HPP__

#include "../Memory/BasicDeleter.hpp"
#include "ResourceObject.hpp"

namespace ntl
{
    // 资源删除器没有数组特化型
    // 因为无法指明具体要删除的元素个数
    // 请使用std::vector之类的代替

    /// @brief 资源删除器
    /// @tparam m_ResourceType 资源对象类型
    template <typename m_ResourceType>
    class NTL_ALIGN ResourceDeleter : public BasicDeleter<m_ResourceType>
    {
    public:
        using ResourceType = m_ResourceType;

        using SelfType = ResourceDeleter<ResourceType>;
        using ParentType = BasicDeleter<ResourceType>;

    public:
        constexpr ResourceDeleter() noexcept = default;
        constexpr ResourceDeleter(const SelfType &from) noexcept = default;
        virtual ~ResourceDeleter() override = default;

    public:
        constexpr SelfType &operator=(const SelfType &from) noexcept = default;
        void operator()(ResourceType *ptr) const override;
    };

} // namespace ntl

#endif
