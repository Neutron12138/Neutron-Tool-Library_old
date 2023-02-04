#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class MyNode
    : public ntl::DefaultNode
{
public:
    ntl::String data;

public:
    MyNode(
        const ntl::String &n,
        const ntl::SharedPointer<ntl::DefaultNode> &p,
        const ntl::String &d)
        : ntl::DefaultNode(n, ntl::WeakPointer(p)), data(d) {}
    MyNode(
        const MyNode &from) = default;

    virtual ~MyNode()
    {
        std::wcout << L"~MyNode()" << L"\t" << m_name << std::endl;
    }
};

/// @brief 遍历并输出
void traverse_all(const ntl::SharedPointer<ntl::DefaultNode> &root, int tabs = 0);

int main()
{
    ntl::SharedPointer<ntl::DefaultNode> root(new MyNode(L"root", ntl::SharedPointer<ntl::DefaultNode>(nullptr), L"root data"));

    ntl::SharedPointer<ntl::DefaultNode> child1(new MyNode(L"child1", root, L"child1 data"));
    ntl::SharedPointer<ntl::DefaultNode> child2(new MyNode(L"child2", root, L"child2 data"));

    ntl::SharedPointer<ntl::DefaultNode> c1child1(new MyNode(L"c1child1", child1, L"c1child1 data"));
    ntl::SharedPointer<ntl::DefaultNode> c1child2(new MyNode(L"c1child2", child1, L"c1child2 data"));
    ntl::SharedPointer<ntl::DefaultNode> c2child1(new MyNode(L"c2child1", child2, L"c2child1 data"));
    ntl::SharedPointer<ntl::DefaultNode> c2child2(new MyNode(L"c2child2", child2, L"c2child2 data"));

    root->add_child_node(L"child1", child1);
    root->add_child_node(L"child2", child2);

    child1->add_child_node(L"c1child1", c1child1);
    child1->add_child_node(L"c1child2", c1child2);
    child2->add_child_node(L"c2child1", c2child1);
    child2->add_child_node(L"c2child2", c2child2);

    std::wcout << L"--------------------" << std::endl;

    traverse_all(root);

    std::wcout << L"--------------------" << std::endl;

    ntl::reset_parent_node(L"child2", child2, root, child1);

    traverse_all(root);

    std::wcout << L"--------------------" << std::endl;

    return 0;
}

void traverse_all(
    const ntl::SharedPointer<ntl::DefaultNode> &root,
    int tabs)
{
    for (int i = 0; i < tabs; i++)
        std::wcout << L"\t";
    std::wcout << root->get_name() << "\t\t"
               << dynamic_cast<MyNode *>(root.get())->data << std::endl;

    auto &nodes = root->get_child_nodes();
    for (auto iter = nodes.cbegin(); iter != nodes.cend(); iter++)
    {
        traverse_all(iter->second, tabs + 1);
    }
}