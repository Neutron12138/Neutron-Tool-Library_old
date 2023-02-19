set filename=test
g++ -finput-charset=UTF-8 -fexec-charset=gbk ^
    "NTL.o" "%filename%.cpp" -o "%filename%.exe"
"%filename%.exe"