# Neutron-Tool-Library
一个简单的C++工具库

## 版本

1.1.3

## 更新说明

## 1.1.3

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
