#include <vector>  //for test
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

namespace jj07
{

	class Bad { };
	class Foo
	{
	public:
		Foo() { cout << "Foo::Foo()" << endl; }
		Foo(int) {
			cout << "Foo::Foo(int)" << endl;
			// throw Bad();  
		}

		//(1) 這個就是一般的 operator new() 的重載 
		void* operator new(size_t size){
			cout << "operator new(size_t size), size= " << size << endl;
			return malloc(size);
		}

		//(2) 這個就是標準庫已經提供的 placement new() 的重載 (形式)
		//    (所以我也模擬 standard placement new 的動作, just return ptr) 
		void* operator new(size_t size, void* start){
			cout << "operator new(size_t size, void* start), size= " << size << "  start= " << start << endl;
			return start;
		}

		//(3) 這個才是嶄新的 placement new 
		void* operator new(size_t size, long extra){
			cout << "operator new(size_t size, long extra)  " << size << ' ' << extra << endl;
			return malloc(size + extra);
		}

		//(4) 這又是一個 placement new 
		void* operator new(size_t size, long extra, char init){
			cout << "operator new(size_t size, long extra, char init)  " << size << ' ' << extra << ' ' << init << endl;
			return malloc(size + extra);
		}

		//(5) 這又是一個 placement new, 但故意寫錯第一參數的 type (它必須是 size_t 以滿足正常的 operator new) 
		//!  	void* operator new(long extra, char init) { //[Error] 'operator new' takes type 'size_t' ('unsigned int') as first parameter [-fpermissive]
		//!	  	cout << "op-new(long,char)" << endl;
		//!    	return malloc(extra);
		//!  	} 	

		//以下是搭配上述 placement new 的各個 called placement delete. 
		//當 ctor 發出異常，這兒對應的 operator (placement) delete 就會被喚起. 
		//應該是要負責釋放其搭檔兄弟 (placement new) 分配所得的 memory.  
		//(1) 這個就是一般的 operator delete() 的重載 
		void operator delete(void*, size_t)
		{
			cout << "operator delete(void*,size_t)  " << endl;
		}

		//(2) 這是對應上述的 (2)  
		void operator delete(void*, void*)
		{
			cout << "operator delete(void*,void*)  " << endl;
		}

		//(3) 這是對應上述的 (3)  
		void operator delete(void*, long)
		{
			cout << "operator delete(void*,long)  " << endl;
		}

		//(4) 這是對應上述的 (4)  
		//如果沒有一一對應, 也不會有任何編譯報錯 
		void operator delete(void*, long, char)
		{
			cout << "operator delete(void*,long,char)  " << endl;
		}

	private:
		int m_i;
	};


	//-------------	
	void test_overload_placement_new()
	{
		cout << "\n\n\ntest_overload_placement_new().......... \n";

		Foo start;  //Foo::Foo

		Foo* p1 = new Foo;           //op-new(size_t)
		Foo* p2 = new (&start) Foo;  //op-new(size_t,void*)
		Foo* p3 = new (100) Foo;     //op-new(size_t,long)
		Foo* p4 = new (100, 'a') Foo; //op-new(size_t,long,char)

		Foo* p5 = new (100) Foo(1);     //op-new(size_t,long)  op-del(void*,long)
		Foo* p6 = new (100, 'a') Foo(1); //
		Foo* p7 = new (&start) Foo(1);  //
		Foo* p8 = new Foo(1);           //
		//VC6 warning C4291: 'void *__cdecl Foo::operator new(unsigned int)'
		//no matching operator delete found; memory will not be freed if
		//initialization throws an exception
	}
} //namespace	

int main(void)
{
	jj07::test_overload_placement_new();
	return 0;
}