/*
C++ 标准库中有一些类代表异常，这些类都是从 exception 类派生而来的。
常用的几个异常类
bad_typeid、bad_cast、bad_alloc、ios_base::failure、out_of_range 
都是 exception 类的派生类。C++ 程序在碰到某些异常时，
即使程序中没有写 throw 语句，也会自动拋出上述异常类的对象。
这些异常类还都有名为 what 的成员函数，返回字符串形式的异常描述信息。
使用这些异常类需要包含头文件 stdexcept。
*/

//使用 typeid 运算符时，如果其操作数是一个多态类的指针，而该指针的值为 NULL，则会拋出此异常。