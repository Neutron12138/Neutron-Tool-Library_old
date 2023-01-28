#ifndef __NEUTRONTL_RESOURCE_RESOURCEDELETER_CPP__
#define __NEUTRONTL_RESOURCE_RESOURCEDELETER_CPP__

#include "ResourceDeleter.hpp"
#include "../Exception/NullPointerException.hpp"

namespace ntl
{
    template <typename m_ResourceObjectType>
    void ResourceDeleter<m_ResourceObjectType>::operator()(typename ResourceDeleter<m_ResourceObjectType>::ResourceObjectType *ptr)
    {
        if (ptr != nullptr)
        {
            ptr->release();
            delete ptr;
        }
        else
        {
            throw NullPointerException(L"template <typename m_ResourceObjectType> void ResourceDeleter<m_ResourceObjectType>::operator()(typename ResourceDeleter<m_ResourceObjectType>::ResourceObjectType *ptr)");
        }
    }

} // namespace ntl

#endif