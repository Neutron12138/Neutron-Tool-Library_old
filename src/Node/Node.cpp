#ifndef __NEUTRONTL_NODE_NODE_CPP__
#define __NEUTRONTL_NODE_NODE_CPP__

#include "Node.hpp"
#include "../Exception/OutOfRangeException.hpp"
#include "../String/StringUtils.hpp"

namespace ntl
{
    template <typename m_ChildNodeType>
    Node<m_ChildNodeType>::Node(
        const String &name)
        : Node<m_ChildNodeType>::ParentType(name) {}

    template <typename m_ChildNodeType>
    typename Node<m_ChildNodeType>::ChildNodeType &
    Node<m_ChildNodeType>::operator[](
        const String &name)
    {
        try
        {
            ChildNodeType &result = m_child_nodes.at(name);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                StringUtils::to_string(
                    NTL_STRING("Attempt to get non-existent child node:\""),
                    name,
                    NTL_STRING("\"")),
                NTL_MAKE_STATEMENT_INFO("template <typename m_ChildNodeType> typename Node<m_ChildNodeType>::ChildNodeType &Node<m_ChildNodeType>::operator[](const String &name)"));
        }
        catch (const std::exception &exception)
        {
            throw Exception(
                StringUtils::to_stl_string(exception.what()),
                NTL_STRING(""),
                NTL_MAKE_STATEMENT_INFO("template <typename m_ChildNodeType> typename Node<m_ChildNodeType>::ChildNodeType &Node<m_ChildNodeType>::operator[](const String &name)"));
        }
    }

    template <typename m_ChildNodeType>
    const typename Node<m_ChildNodeType>::ChildNodeHolder &
    Node<m_ChildNodeType>::get_child_nodes() const
    {
        return m_child_nodes;
    }

    template <typename m_ChildNodeType>
    const typename Node<m_ChildNodeType>::ChildNodeType &
    Node<m_ChildNodeType>::get_child_node(
        const String &name) const
    {
        try
        {
            const typename Node<m_ChildNodeType>::ChildNodeType &result = m_child_nodes.at(name);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw OutOfRangeException(
                StringUtils::to_string(
                    NTL_STRING("Attempt to get non-existent child node:\""),
                    name,
                    NTL_STRING("\"")),
                NTL_MAKE_STATEMENT_INFO("template <typename m_ChildNodeType> const typename Node<m_ChildNodeType>::ChildNodeType &Node<m_ChildNodeType>::get_child_node(const String &name) const"));
        }
        catch (const std::exception &exception)
        {
            throw Exception(
                StringUtils::to_stl_string(
                    exception.what()),
                NTL_STRING(""),
                NTL_MAKE_STATEMENT_INFO("template <typename m_ChildNodeType> const typename Node<m_ChildNodeType>::ChildNodeType &Node<m_ChildNodeType>::get_child_node(const String &name) const"));
        }
    }

    template <typename m_ChildNodeType>
    void
    Node<m_ChildNodeType>::set_child_node(
        const String &name,
        const typename Node<m_ChildNodeType>::ChildNodeType &child_node)
    {
        operator[](name) = child_node;
    }

    template <typename m_ChildNodeType>
    void
    Node<m_ChildNodeType>::add_child_node(
        const String &name,
        const typename Node<m_ChildNodeType>::ChildNodeType &child_node)
    {
        m_child_nodes.insert(
            std::pair<
                String,
                typename Node<m_ChildNodeType>::ChildNodeType>(
                name,
                child_node));
    }

    template <typename m_ChildNodeType>
    void
    Node<m_ChildNodeType>::remove_child_node(
        const String &name)
    {
        auto iter = m_child_nodes.find(name);
        if (iter != m_child_nodes.cend())
        {
            m_child_nodes.erase(iter);
        }
    }

    template <typename m_ChildNodeType>
    bool
    Node<m_ChildNodeType>::is_exist(
        const String &name) const
    {
        auto iter = m_child_nodes.find(name);
        return iter != m_child_nodes.cend();
    }

    template <typename m_ChildNodeType>
    bool
    Node<m_ChildNodeType>::has_childs() const
    {
        return !m_child_nodes.empty();
    }

    template <typename m_ChildNodeType>
    void
    Node<m_ChildNodeType>::clear_all()
    {
        m_child_nodes.clear();
    }

} // namespace ntl

#endif