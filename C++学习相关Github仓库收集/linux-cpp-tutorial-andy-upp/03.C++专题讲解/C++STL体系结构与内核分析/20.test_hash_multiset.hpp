以下測試 hash_multiset, hash_multimap 過程中遇到阻礙：
headers <hash_set> 和 <hash_map> 各有兩個，
分別在 ...\4.9.2\include\c++\backward 和 ...\4.9.2\include\c++\ext，
不知要用哪一組! 
用 <ext\...> 那一組會有問題 
   ...\4.9.2\include\c++\backward\hashtable.h 
   [Error] no match for call to '(const hasher {aka const __gnu_cxx::hash<std::basic_string<char> >}) (const key_type&)'
用 <backward\...> 那一組有相同的問題.  
so, 放棄測試 (no insertion or push_back or ...).  
*/

#include <ext\hash_set>		
    //...\4.9.2\include\c++\backward\backward_warning.h	
	//[Warning] #warning This file includes at least one deprecated or antiquated header 
	//which may be removed without further notice at a future date. 
	//Please use a non-deprecated interface with equivalent functionality instead. 
	//For a listing of replacement headers and interfaces, consult the file backward_warning.h. 
	//To disable this warning use -Wno-deprecated. [-Wcpp]
	
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace jj11
{
void test_hash_multiset(long& value)
{
	cout << "\ntest_hash_multiset().......... \n";
   
	__gnu_cxx::hash_multiset<string> c;  	
	char buf[10];
			
    clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	//! c.insert(string(buf));     		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;				
}															 
}