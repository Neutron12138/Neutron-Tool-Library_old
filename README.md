# Neutron-Tool-Library

一个简单的C++工具库

## 版本

1.2.3

## 更新说明

### 1.2.3

做了些修改。

完善异常信息。

ResourceDeleter出了些问题，无法作为std::shared_ptr的删除器，原因不明。

### 1.2.2

废除了序列化器和反序列化器，而是改用重载函数

但依然没有增加对字符串容器的特化

### 1.2.1

对位图类做了些修改

### 1.2.0

做了些改进

### 1.1.14

让数学库兼容GLM

### 1.1.13

增加了一些基于C++20的代码

### 1.1.12

做了些修改，增加了字符串枚举模板特化

### 1.1.11

增加了枚举类，可以继承

### 1.1.10

增加了矩阵与向量

这是一个很离谱的数学库，所有运算符重载都是纯粹的每个分量相操作，一点也不数学

点乘、叉乘、矩阵乘法等需要用到特定的函数

### 1.1.9

增加了信号

### 1.1.8

增加了侵入式反射

### 1.1.7

增加了序列化与反序列化

### 1.1.6

增加了图像加载与导出

### 1.1.5

增加了控制台程序（ConsoleApplication）

### 1.1.4

做了些简单的修改

### 1.1.3

增加了CaughtException

现在可以传递异常与异常发生的位置

### 1.1.2

把脚本部分拆分了出去

https://github.com/Neutron12138/Neutron-Script-Language

### 1.1.1

修改了Application，增加了两个run()的重载函数

Application::run(int,char**)负责处理main(int,char**)提供的参数，并转换为std::vector<std::string>，用作run(const std::vector<std::string>&)的参数

Application::run(const std::vector<std::string>&)负责真正地处理参数，处理参数只要重载此函数即可

Application::run()负责主程序运行

定义宏NEUTRONTL_CONFIG_USE_APPLICATION可以使用默认的main()函数，只要实现get_application()即可

### 1.1.0

增加了脚本的一些基础部分

之后的更新会围绕着这个新的脚本语言——Neutron Script Language

下一次应该会把基础类型部分做完（integer、floating、string、byte、boolean）
