#include <unordered_map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace jj16
{
void test_unordered_map(long& value)
{
	cout << "\ntest_unordered_map().......... \n";

unordered_map<long, string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
			c[i] = string(buf);  		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_map.size()= " << c.size() << endl;	//357913941
	cout << "unordered_map.max_size()= " << c.max_size() << endl;	
	
long target = get_a_target_long();		
    timeStart = clock();	
//! auto pItem = find(c.begin(), c.end(), target);	//map 不適用 std::find() 			
auto pItem = c.find(target);
						
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;		
}															 
}