#include <functional>
#include <list>
//function
//lambda

int funA(int a, int b)
{
	printf("funA\n");
	return 0;
}

int main()
{
	//std::list< int > a;
	//std::function< int(int, int) > call = funA;
	//int n = call(0,2);

	std::function< int(int,int) > call;

	int n = 5;
	//匿名函数
	call = [n/*外部变量捕获列表*/](/*参数列表*/int a,int b) -> int/*返回值类型*/
	{
		//函数体
		printf("%d\n",n+a+b);
		return 2;
	};

	int f = call(3,1);
	return 0;
}

/* lambda表达式  拉曼达表达式 匿名函数
[ caputrue ] ( params ) opt -> ret { body; };

[ 外部变量捕获列表 ] ( 参数表 ) 特殊操作符 -> 返回值类型 { 函数体; };

捕获列表：lambda表达式的捕获列表精细控制了lambda表达式能够访问的外部变量，以及如何访问这些变量。

1) []不捕获任何变量。

2) [&]捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）。

3) [=]捕获外部作用域中所有变量，并作为副本在函数体中使用(按值捕获)。

4) [=, &foo]按值捕获外部作用域中所有变量，并按引用捕获foo变量。

5) [bar]按值捕获bar变量，同时不捕获其他变量。

6) [this]捕获当前类中的this指针，让lambda表达式拥有和当前类成员函数同样的访问权限。
如果已经使用了&或者 = ，就默认含有此选项。
捕获this的目的是可以在lamda中使用当前类的成员函数和成员变量。

////////
1).capture是捕获列表；

2).params是参数表；(选填)

3).opt是函数选项；可以填mutable,exception,attribute（选填）

mutable说明lambda表达式体内的代码可以修改被捕获的变量，并且可以访问被捕获的对象的non-const方法。

exception说明lambda表达式是否抛出异常以及何种异常。

attribute用来声明属性。

4).ret是返回值类型。(选填)

5).body是函数体。
*/