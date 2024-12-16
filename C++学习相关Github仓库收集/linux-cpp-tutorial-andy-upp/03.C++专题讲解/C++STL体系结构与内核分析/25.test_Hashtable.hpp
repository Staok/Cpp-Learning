#include <unordered_set>
#include <functional>
#include <iostream>
#include <string>
namespace jj32
{
/*
//下面的 hash<string>, G2.9需要，G4.9不需要，因為 G4.9 basic_string.h 已提供 
template<> struct hash<string>
{
  size_t operator()(string s) const {
      return __stl_hash_string(s.c_str()); 
  }
};
*/
	
void test_Hashtable()
{
	cout << "\ntest_Hashtable().......... \n";
  
// hashtable 的模板參數個數 6=>10 (增加 hash policy 吧大概)
// 所以 G2.9的應用修改起來很麻煩。不改了, 以後再說. 	    
}															 
}