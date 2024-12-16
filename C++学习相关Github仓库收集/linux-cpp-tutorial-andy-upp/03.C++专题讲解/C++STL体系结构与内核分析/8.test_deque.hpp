#include <deque>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace jj05
{
void test_deque(long& value)
{
	cout << "\ntest_deque().......... \n";
     
deque<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "deque.size()= " << c.size() << endl;
	cout << "deque.front()= " << c.front() << endl;	
	cout << "deque.back()= " << c.back() << endl;	
	cout << "deque.max_size()= " << c.max_size() << endl;	//1073741821	
	
string target = get_a_target_string();	
    timeStart = clock();			
auto pItem = find(c.begin(), c.end(), target);	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;	
	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	sort(c.begin(), c.end());						
	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl;		
	
	c.clear();
	test_moveable(deque<MyString>(),deque<MyStrNoMove>(), value);		 						
}															
}