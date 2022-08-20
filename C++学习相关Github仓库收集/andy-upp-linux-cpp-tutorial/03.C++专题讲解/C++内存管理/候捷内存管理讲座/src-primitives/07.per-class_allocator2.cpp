#include <cstddef>
#include <iostream>
using namespace std;

namespace jj05
{
	//ref. Effective C++ 2e, item10
	//per-class allocator 

	class Airplane {   //支援 customized memory management
	private:
		struct AirplaneRep {
			unsigned long miles;
			char type;
		};
	private:
		union {
			AirplaneRep rep;  //此針對 used object
			Airplane* next;   //此針對 free list
		};
	public:
		unsigned long getMiles() { return rep.miles; }
		char getType() { return rep.type; }
		void set(unsigned long m, char t)
		{
			rep.miles = m;
			rep.type = t;
		}
	public:
		static void* operator new(size_t size);
		static void  operator delete(void* deadObject, size_t size);
	private:
		static const int BLOCK_SIZE;
		static Airplane* headOfFreeList;
	};

	Airplane* Airplane::headOfFreeList;
	const int Airplane::BLOCK_SIZE = 512;

	void* Airplane::operator new(size_t size)
	{
		//如果大小錯誤，轉交給 ::operator new()
		if (size != sizeof(Airplane))
		return ::operator new(size);

		Airplane* p = headOfFreeList;

		//如果 p 有效，就把list頭部移往下一個元素
		if (p)
			headOfFreeList = p->next;
		else {
			//free list 已空。配置一塊夠大記憶體，
			//令足夠容納 BLOCK_SIZE 個 Airplanes
			Airplane* newBlock = static_cast<Airplane*>
				(::operator new(BLOCK_SIZE * sizeof(Airplane)));
			//組成一個新的 free list：將小區塊串在一起，但跳過 
			//#0 元素，因為要將它傳回給呼叫者。
			for (int i = 1; i < BLOCK_SIZE - 1; ++i)
				newBlock[i].next = &newBlock[i + 1];
			newBlock[BLOCK_SIZE - 1].next = 0; //以null結束

			// 將 p 設至頭部，將 headOfFreeList 設至
			// 下一個可被運用的小區塊。
			p = newBlock;
			headOfFreeList = &newBlock[1];
		}
		return p;
	}

	// operator delete 接獲一塊記憶體。
	// 如果它的大小正確，就把它加到 free list 的前端
	void Airplane::operator delete(void* deadObject,
		size_t size)
	{
		if (deadObject == 0) return;
		if (size != sizeof(Airplane)) {
			::operator delete(deadObject);
			return;
		}

		Airplane *carcass =
			static_cast<Airplane*>(deadObject);

		carcass->next = headOfFreeList;
		headOfFreeList = carcass;
	}

	//-------------
	void test_per_class_allocator_2()
	{
		cout << "\ntest_per_class_allocator_2().......... \n";

		cout << sizeof(Airplane) << endl;    //8

		size_t const N = 100;
		Airplane* p[N];

		for (int i = 0; i< N; ++i)
			p[i] = new Airplane;


		//隨機測試 object 正常否 
		p[1]->set(1000, 'A');
		p[5]->set(2000, 'B');
		p[9]->set(500000, 'C');
		cout << p[1] << ' ' << p[1]->getType() << ' ' << p[1]->getMiles() << endl;
		cout << p[5] << ' ' << p[5]->getType() << ' ' << p[5]->getMiles() << endl;
		cout << p[9] << ' ' << p[9]->getType() << ' ' << p[9]->getMiles() << endl;

		//輸出前 10 個 pointers, 用以比較其間隔 
		for (int i = 0; i< 10; ++i)
			cout << p[i] << endl;

		for (int i = 0; i< N; ++i)
			delete p[i];
	}
} //namespace

int main(void)
{
	jj05::test_per_class_allocator_2();
	return 0;
}