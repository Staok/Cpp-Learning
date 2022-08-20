 #include <iostream>
#include <cstdio>  //snprintf()
#include <cstdlib> //RAND_MAX
#include <string> 
#include <algorithm> 
#include <list> 
#include <forward_list> 
using std::cin;
using std::cout;
using std::string;
using std::max;
using std::min;

namespace jj00
{
	
bool strLonger(const string& s1, const string& s2) {
          return s1.size() < s2.size();
}		
	
void test_misc()
{
	cout << "\ntest_misc().......... \n";
     
    //以下這些是標準庫的眾多容器的 max_size() 計算方式.  
    cout << size_t(-1) << endl;					         	//4294967295
	cout << size_t(-1)/sizeof(long) << endl;		     	//1073741823
	cout << size_t(-1)/sizeof(string) << endl;	         	//1073741823
	cout << size_t(-1)/sizeof(_List_node<string>) << endl; 	//357913941
	cout << size_t(-1)/sizeof(_Fwd_list_node<string>) << endl; //536870911
	cout << "RAND_MAX= " << RAND_MAX << endl;	//32767
	
	cout << min( {2,5,8,9,45,0,81} ) << endl;  //0
	cout << max( {2,5,8,9,45,0,81} ) << endl;  //81
	vector<int> v {2,5,8,9,45,0,81};               
         
	cout << "max of     zoo and hello : " 
	     << max(string("zoo"), string("hello")) << endl;              //zoo
	cout << "longest of zoo and hello : " 
	     << max(string("zoo"), string("hello"), strLonger) << endl;   //hello    
		 
	cout << hash<MyString>()(MyString("Ace")) << endl;		//1765813650
	cout << hash<MyString>()(MyString("Stacy")) << endl;	//2790324277
	cout << "MyString(zoo) < MyString(hello) ==> " << (MyString("zoo") < MyString("hello")) << endl;	//0
	cout << "MyString(zoo) == MyString(hello) ==> " << (MyString("zoo") == MyString("hello")) << endl;	//0	  
	cout << "MyStrNoMove(zoo) < MyStrNoMove(hello) ==> " << (MyStrNoMove("zoo") < MyStrNoMove("hello")) << endl;	 //0
	cout << "MyStrNoMove(zoo) == MyStrNoMove(hello) ==> " << (MyStrNoMove("zoo") == MyStrNoMove("hello")) << endl;	 //0
	//以上建構了 6 個 MyString objects 和 4 個 MyStrNoMove objects，都是暫時生命.    
}
}    