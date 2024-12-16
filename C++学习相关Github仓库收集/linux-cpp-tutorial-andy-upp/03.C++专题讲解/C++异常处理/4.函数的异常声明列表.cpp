/*

为了增强程序的可读性和可维护性，使程序员在使用一个函数时就能看出这个函数可能会拋出哪些异常，
C++ 允许在函数声明和定义时，加上它所能拋出的异常的列表，具体写法如下：
void func() throw (int, double, A, B, C);

或
void func() throw (int, double, A, B, C){...}
*/