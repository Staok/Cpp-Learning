#include <stack>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace jj17
{
void test_stack(long& value)
{
	cout << "\ntest_stack().......... \n";
     
stack<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	
	
	{
stack<string, list<string>> c;		//以 list 為底層 
    for(long i=0; i< 10; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
    }	
	
	{
stack<string, vector<string>> c;	//以 vector 為底層 
    for(long i=0; i< 10; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
    }

	{
stack<string, set<string>> c;	//以 set 為底層 
/*!
    for(long i=0; i< 10; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	
//[Error] 'class std::set<std::basic_string<char> >' has no member named 'push_back'
//[Error] 'class std::set<std::basic_string<char> >' has no member named 'back'
//[Error] 'class std::set<std::basic_string<char> >' has no member named 'pop_back'
*/
    }
			
//!stack<string, map(string>> c5;	////以 map 為底層, [Error] template argument 2 is invalid
//!stack<string>::iterator ite1;  	//[Error] 'iterator' is not a member of 'std::stack<std::basic_string<char> >'
		
}															
}