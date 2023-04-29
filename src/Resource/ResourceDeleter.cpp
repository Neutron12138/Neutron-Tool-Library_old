#ifndef __NEUTRONTL_RESOURCE_RESOURCEDELETER_CPP__
#define __NEUTRONTL_RESOURCE_RESOURCEDELETER_CPP__

#include "ResourceDeleter.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename m_ResourceObjectType>
    void
    ResourceDeleter<m_ResourceObjectType>::operator()(
        typename ResourceDeleter<m_ResourceObjectType>::ResourceObjectType *ptr) const
    {
        if (ptr == nullptr)
            throw NullPointerException(
                NTL_MAKE_STATEMENT_INFO("template <typename m_ResourceObjectType> void ResourceDeleter<m_ResourceObjectType>::operator()(typename ResourceDeleter<m_ResourceObjectType>::ResourceObjectType *ptr) const"));

        ptr->release();
        delete ptr;
    }

} // namespace ntl

#endif