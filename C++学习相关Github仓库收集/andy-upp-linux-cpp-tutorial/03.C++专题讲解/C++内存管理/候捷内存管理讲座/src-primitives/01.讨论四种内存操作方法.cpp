#include <iostream>
#include <complex>
#include <memory>				 //std::allocator  
//#include <ext\pool_allocator.h>	 //GCC使用，欲使用 std::allocator 以外的 allocator, 就得自行 #include <ext/...> 
using namespace std;
namespace jj01
{
	void test_primitives()
	{
		cout << "\ntest_primitives().......... \n";

		void* p1 = malloc(512);	//512 bytes
		free(p1);

		complex<int>* p2 = new complex<int>; //one object
		delete p2;

		void* p3 = ::operator new(512); //512 bytes
		::operator delete(p3);

		//以下使用 C++ 標準庫提供的 allocators。
		//其接口雖有標準規格，但實現廠商並未完全遵守；下面三者形式略異。
#ifdef _MSC_VER
		//以下兩函數都是 non-static，定要通過 object 調用。以下分配 3 個 ints.
		int* p4 = allocator<int>().allocate(3, (int*)0);
		p4[0] = 666;
		p4[1] = 999;
		p4[2] = 888;
		cout << "p4[0] = " << p4[0] << endl;
		cout << "p4[1] = " << p4[1] << endl;
		cout << "p4[2] = " << p4[2] << endl;
		allocator<int>().deallocate(p4, 3);
#endif
#ifdef __BORLANDC__
		//以下兩函數都是 non-static，定要通過 object 調用。以下分配 5 個 ints.
		int* p4 = allocator<int>().allocate(5);
		allocator<int>().deallocate(p4, 5);
#endif
#ifdef __GNUC__
		//以下兩函數都是 static，可通過全名調用之。以下分配 512 bytes.
		//void* p4 = alloc::allocate(512); 
		//alloc::deallocate(p4,512);   

		//以下兩函數都是 non-static，定要通過 object 調用。以下分配 7 個 ints.    
		void* p4 = allocator<int>().allocate(7);
		allocator<int>().deallocate((int*)p4, 7);

		//以下兩函數都是 non-static，定要通過 object 調用。以下分配 9 個 ints.	
		void* p5 = __gnu_cxx::__pool_alloc<int>().allocate(9);
		__gnu_cxx::__pool_alloc<int>().deallocate((int*)p5, 9);
#endif
	}
} //namespace

int main(void)
{
	jj01::test_primitives();
	return 0;
}