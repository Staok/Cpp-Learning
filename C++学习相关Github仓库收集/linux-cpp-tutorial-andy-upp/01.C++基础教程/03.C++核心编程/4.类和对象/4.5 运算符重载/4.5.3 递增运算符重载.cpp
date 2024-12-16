 #include<iostream>
 using namespace std;

 /*
 作用： 通过重载递增运算符，实现自己的整型数据
 总结： 前置递增返回引用，后置递增返回值
 */

class MyInteger {

	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() {
		m_Num = 0;
	}
	//重载++运算符，重载前置++，返回引用是为了一直对一个数据进行递增操作
	MyInteger& operator++() {
		//先做++运算
		m_Num++;
		//再把执行++之后的自身解引用返回
		return *this;
	}

	//重载后置++，两个operator++本身也是函数重载，而int代表占位参数，可以用于区分前置和后置递增
    //加了int参数，则编译器就认为是重载后置递增
	MyInteger operator++(int) {
		//先返回，记录当前结果
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
        //如果返回值是引用，则相当于返回了一个局部对象的引用，但是局部对象在当前函数执行完之后
        //就被释放了，如果返回的是引用，后面就是非法操作了 
		return temp;
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}


//前置++ 先++ 再返回
void test01() {
	MyInteger myInt;
	cout << ++myInt << endl;
	cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

	MyInteger myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main() {

	test01();
	//test02();

	system("pause");

	return 0;
}