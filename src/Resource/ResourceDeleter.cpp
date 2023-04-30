#ifndef __NEUTRONTL_RESOURCE_RESOURCEDELETER_CPP__
#define __NEUTRONTL_RESOURCE_RESOURCEDELETER_CPP__

#include "ResourceDeleter.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename m_ResourceType>
    void
    ResourceDeleter<m_ResourceType>::operator()(
        typename ResourceDeleter<m_ResourceType>::ResourceType *ptr) const
    {
        if (ptr == nullptr)
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_ResourceType> void ResourceDeleter<m_ResourceType>::operator()(typename ResourceDeleter<m_ResourceType>::ResourceType *ptr) const"));

        ptr->release();
        delete ptr;
    }

} // namespace ntl

#endif
