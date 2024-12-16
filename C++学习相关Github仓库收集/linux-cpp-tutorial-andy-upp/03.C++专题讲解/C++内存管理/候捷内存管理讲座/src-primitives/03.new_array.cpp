#include <iostream>
#include <new>		//placement new
using namespace std;

namespace jj03
{

	class A
	{
	public:
		int id;

		A() : id(0)      { cout << "default ctor. this=" << this << " id=" << id << endl; }
		A(int i) : id(i) { cout << "ctor. this=" << this << " id=" << id << endl; }
		~A()             { cout << "dtor. this=" << this << " id=" << id << endl; }
	};

	void test_array_new_and_placement_new()
	{
		cout << "\ntest_placement_new().......... \n";

		size_t size = 3;

		{
			//case 1
			//模擬 memory pool 的作法, array new + placement new. 崩潰 

			A* buf = (A*)(new char[sizeof(A)*size]);
			A* tmp = buf;

			cout << "buf=" << buf << "  tmp=" << tmp << endl;

			for (int i = 0; i < size; ++i)
				new (tmp++) A(i);  			//3次 调用ctor 

			cout << "buf=" << buf << "  tmp=" << tmp << endl;

			//!	delete [] buf;    	//crash. why?
			//因為這其實是個 char array，看到 delete [] buf; 編譯器會企圖喚起多次 A::~A. 
			// 但 array memory layout 中找不到與 array 元素個數 (本例 3) 相關的信息, 
			// -- 整個格局都錯亂 (從我對 VC 的認識而言)，於是崩潰。 
			delete buf;     	//dtor just one time, ~[0]	

			cout << "\n\n";
		}

		{
			//case 2
			//回頭測試單純的 array new

			A* buf = new A[size];  //default ctor 3 次. [0]先於[1]先於[2])
			//A必須有 default ctor, 否則 [Error] no matching function for call to 'jj02::A::A()'
			A* tmp = buf;

			cout << "buf=" << buf << "  tmp=" << tmp << endl;

			for (int i = 0; i < size; ++i)
				new (tmp++) A(i);  		//3次 ctor 

			cout << "buf=" << buf << "  tmp=" << tmp << endl;

			delete[] buf;    //dtor three times (次序逆反, [2]先於[1]先於[0])	
		}

		{
			//case 3	
			//掌握崩潰原因, 再次模擬 memory pool作法, array new + placement new. 	
			//不, 不做了, 因為 memory pool 只是供應 memory, 它並不管 construction, 
			//也不管 destruction. 它只負責回收 memory. 
			//所以它是以 void* 或 char* 取得 memory, 釋放 (刪除)的也是 void* or char*.  
			//不像本例 case 1 釋放 (刪除) 的是 A*. 
			//
			//事實上 memory pool 形式如 jj04::test 
		}

	}
} //namespace

int main(void)
{
	jj03::test_array_new_and_placement_new();
	return 0;
}