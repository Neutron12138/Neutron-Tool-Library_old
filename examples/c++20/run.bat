set filename=main
g++ -finput-charset=UTF-8 -fexec-charset=gbk -std=c++20 ^
    "%filename%.cpp" -o "%filename%.exe"
"%filename%.exe"