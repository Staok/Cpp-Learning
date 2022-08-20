#include <list>
#include <string>
#include <iostream>

#include <memory>		//內含 std::allocator  
//#include <bits\stl_tree.h>  //內含 _RB_tree (不需此行, 因為它被含入於 <set> and <map>)

//欲使用 std::allocator 以外的 allocator, 得自行 #include <ext\...> 
#include <ext\array_allocator.h>
#include <ext\mt_allocator.h>
#include <ext\debug_allocator.h>
#include <ext\pool_allocator.h>
#include <ext\bitmap_allocator.h>
#include <ext\malloc_allocator.h>
#include <ext\new_allocator.h>  

namespace jj25
{
void test_components_sizeof()
{
	cout << "\ntest_components_size().......... \n";
	
	//containers
	cout << "sizeof(array<int,100>)= " << sizeof(array<int,100>) << endl;		//400
	cout << "sizeof(vector<int>)= " << sizeof(vector<int>) << endl;				//12
	cout << "sizeof(list<int>)= " << sizeof(list<int>) << endl;					//8
	cout << "sizeof(forward_list<int>)= " << sizeof(forward_list<int>) << endl;	//4
	cout << "sizeof(deque<int>)= " << sizeof(deque<int>) << endl;				//40
	cout << "sizeof(stack<int>)= " << sizeof(stack<int>) << endl;				//40
	cout << "sizeof(queue<int>)= " << sizeof(queue<int>) << endl;				//40
	cout << "sizeof(set<int>)= " << sizeof(set<int>) << endl;					//24
	cout << "sizeof(map<int,int>)= " << sizeof(map<int,int>) << endl;			//24
	cout << "sizeof(multiset<int>)= " << sizeof(multiset<int>) << endl;			//24
	cout << "sizeof(multimap<int,int>)= " << sizeof(multimap<int,int>) << endl;	//24
	cout << "sizeof(unordered_set<int>)= " << sizeof(unordered_set<int>) << endl;					//28
	cout << "sizeof(unordered_map<int,int>)= " << sizeof(unordered_map<int,int>) << endl;			//28	
	cout << "sizeof(unordered_multiset<int>)= " << sizeof(unordered_multiset<int>) << endl;			//28
	cout << "sizeof(unordered_multimap<int,int>)= " << sizeof(unordered_multimap<int,int>) << endl;	//28
	cout << "sizeof(_Rb_tree<...>)= " << sizeof(_Rb_tree<int,int,_Identity<int>,less<int>>) << endl; //24
	
	//iterators
	cout << "sizeof(array<int,100>::iterator)= " << sizeof(array<int,100>::iterator) << endl;		//4
	cout << "sizeof(vector<int>::iterator)= " << sizeof(vector<int>::iterator) << endl;				//4
	cout << "sizeof(list<int>::iterator)= " << sizeof(list<int>::iterator) << endl;					//4
	cout << "sizeof(forward_list<int>::iterator)= " << sizeof(forward_list<int>::iterator) << endl; //4
	cout << "sizeof(deque<int>::iterator)= " << sizeof(deque<int>::iterator) << endl;				//16
	//! cout << "sizeof(stack<int>::iterator)= " << sizeof(stack<int>::iterator) << endl;	//[Error] 'iterator' is not a member of 'std::stack<int>'		
	//! cout << "sizeof(queue<int>::iterator)= " << sizeof(queue<int>::iterator) << endl;	//[Error] 'iterator' is not a member of 'std::queue<int>			
	cout << "sizeof(set<int>::iterator)= " << sizeof(set<int>::iterator) << endl;					//4
	cout << "sizeof(map<int,int>::iterator)= " << sizeof(map<int,int>::iterator) << endl;			//4
	cout << "sizeof(multiset<int>::iterator)= " << sizeof(multiset<int>::iterator) << endl;			//4
	cout << "sizeof(multimap<int,int>::iterator)= " << sizeof(multimap<int,int>::iterator) << endl;	//4
	cout << "sizeof(unordered_set<int>::iterator)= " << sizeof(unordered_set<int>::iterator) << endl;	//4	
	cout << "sizeof(unordered_map<int,int>::iterator)= " << sizeof(unordered_map<int,int>::iterator) << endl;	//4	
	cout << "sizeof(unordered_multiset<int>::iterator)= " << sizeof(unordered_multiset<int>::iterator) << endl;	//4
	cout << "sizeof(unordered_multimap<int,int>::iterator)= " << sizeof(unordered_multimap<int,int>::iterator) << endl;	//4										
	cout << "sizeof(_Rb_tree<...>::iterator)= " << sizeof(_Rb_tree<int,int,_Identity<int>,less<int>>::iterator) << endl; //4
		 		
	//allocators
	cout << "sizeof(      std::allocator<string>)=" << sizeof(std::allocator<string>) << endl;						//1 (理論值 0)
	cout << "sizeof(__gnu_cxx::malloc_allocator<string>)= " << sizeof(__gnu_cxx::malloc_allocator<string>) << endl; //1 (理論值 0) 
    cout << "sizeof(__gnu_cxx::new_allocator<string>)= " <<  sizeof(__gnu_cxx::new_allocator<string>) << endl; 	    //1 (理論值 0)
	cout << "sizeof(__gnu_cxx::__pool_alloc<string>)= " << sizeof(__gnu_cxx::__pool_alloc<string>) << endl;         //1 (理論值 0)
    cout << "sizeof(__gnu_cxx::bitmap_allocator<string>)= " << sizeof(__gnu_cxx::bitmap_allocator<string>) << endl; //1 (理論值 0)
	cout << "sizeof(__gnu_cxx::__mt_alloc<string>)= " << sizeof(__gnu_cxx::__mt_alloc<string>) << endl;  			//1 (理論值 0)
	cout << "sizeof(__gnu_cxx::array_allocator<int>)= " << sizeof(__gnu_cxx::array_allocator<int>) << endl;  		//8
	    													//==> 因為它有一個 ptr 指向 array 和一個 size_t 表示消耗到 array 哪兒 
	cout << "sizeof(__gnu_cxx::debug_allocator<std::allocator<double>>)= " << sizeof(__gnu_cxx::debug_allocator<std::allocator<double>>) << endl; //8 	
}															
}