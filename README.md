# Neutron-Tool-Library
一个简单的C++工具库

## 新增内容

增加了弱引用指针（Memory/WeakPointer）

完成了节点类，其析构函数为虚函数，并有智能指针，无需担心释放问题

使用节点时只要继承DefaultNode便可

但是Tree类未经过测试，之后会对其修改

## 之后更新

1.节点树（Node/Tree）（也许）

2.csv文件数据（CSV/CSVData）、csv文件（CSV/CSVFile），并提供其文件导入/导出

3.基于csv文件的语言文件（CSV/LanguageData与CSV/LanguageFile），建议后缀：.lang或.csv（然而实际不检查）
