#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

namespace jj06
{

	class Foo
	{
	public:
		int _id;
		long _data;
		string _str;

	public:
		static void* operator new(size_t size);
		static void  operator delete(void* deadObject, size_t size);
		static void* operator new[](size_t size);
		static void  operator delete[](void* deadObject, size_t size);

		Foo() : _id(0)      { cout << "default ctor. this=" << this << " id=" << _id << endl; }
		Foo(int i) : _id(i) { cout << "ctor. this=" << this << " id=" << _id << endl; }
		//virtual 
		~Foo()              { cout << "dtor. this=" << this << " id=" << _id << endl; }

		//不加 virtual dtor, sizeof = 12, new Foo[5] => operator new[]() 的 size 參數是 64, 
		//加了 virtual dtor, sizeof = 16, new Foo[5] => operator new[]() 的 size 參數是 84, 
		//上述二例，多出來的 4 可能就是個 size_t 欄位用來放置 array size. 
	};

	void* Foo::operator new(size_t size)
	{
		Foo* p = (Foo*)malloc(size);
		cout << "Foo::operator new(), size=" << size << "\t  return: " << p << endl;

		return p;
	}

	void Foo::operator delete(void* pdead, size_t size)
	{
		cout << "Foo::operator delete(), pdead= " << pdead << "  size= " << size << endl;
		free(pdead);
	}

	void* Foo::operator new[](size_t size)
	{
		Foo* p = (Foo*)malloc(size);  //crash, 問題可能出在這兒 
		cout << "Foo::operator new[](), size=" << size << "\t  return: " << p << endl;

		return p;
	}

	void Foo::operator delete[](void* pdead, size_t size)
	{
		cout << "Foo::operator delete[](), pdead= " << pdead << "  size= " << size << endl;

		free(pdead);
	}

	//-------------	
	void test_overload_operator_new_and_array_new()
	{
		cout << "\ntest_overload_operator_new_and_array_new().......... \n";

		cout << "sizeof(Foo)= " << sizeof(Foo) << endl;

		{
			Foo* p = new Foo(7);
			delete p;

			Foo* pArray = new Foo[5];	//無法給 array elements 以 initializer 
			delete[] pArray;
		}

		{
			cout << "testing global expression ::new and ::new[] \n";
			// 這會繞過 overloaded new(), delete(), new[](), delete[]() 
			// 但當然 ctor, dtor 都會被正常呼叫.  

			Foo* p = ::new Foo(7);
			::delete p;

			Foo* pArray = ::new Foo[5];
			::delete[] pArray;
		}
	}
} //namespace

int main(void)
{
	jj06::test_overload_operator_new_and_array_new();
	return 0;
}