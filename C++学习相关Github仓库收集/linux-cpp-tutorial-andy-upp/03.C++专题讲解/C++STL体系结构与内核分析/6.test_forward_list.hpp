#include <forward_list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 

namespace jj04
{
void test_forward_list(long& value)
{
	cout << "\ntest_forward_list().......... \n";
     
forward_list<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_front(string(buf));  			   		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "forward_list.max_size()= " << c.max_size() << endl;  //536870911
	cout << "forward_list.front()= " << c.front() << endl;	


string target = get_a_target_string();	
    timeStart = clock();			
auto pItem = find(c.begin(), c.end(), target);	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	c.sort();						
	cout << "c.sort(), milli-seconds : " << (clock()-timeStart) << endl;		
	
	c.clear();	 
}											 
}