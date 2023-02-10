set filename=main
g++ -finput-charset=UTF-8 -fexec-charset=gbk -m64 ^
    "%filename%.cpp" -o "%filename%.exe"
"%filename%.exe"