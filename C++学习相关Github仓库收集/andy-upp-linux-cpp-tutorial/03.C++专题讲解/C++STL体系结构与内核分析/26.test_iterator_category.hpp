#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
namespace jj33
{
void _display_category(random_access_iterator_tag)
{   cout << "random_access_iterator" << endl; }
void _display_category(bidirectional_iterator_tag)
{   cout << "bidirectional_iterator" << endl; }
void _display_category(forward_iterator_tag)
{   cout << "forward_iterator" << endl;  }
void _display_category(output_iterator_tag)
{   cout << "output_iterator" << endl;   }
void _display_category(input_iterator_tag)
{   cout << "input_iterator" << endl;    }

template<typename I>
void display_category(I itr)
{
   typename iterator_traits<I>::iterator_category cagy;
   _display_category(cagy);
   
   cout << "typeid(itr).name()= " << typeid(itr).name() << endl << endl;   
       //The output depends on library implementation.
       //The particular representation pointed by the  
	   //returned valueis implementation-defined, 
	   //and may or may not be different for different types.   
}
	
void test_iterator_category()
{
	cout << "\ntest_iterator_category().......... \n";
  	
  	display_category(array<int,10>::iterator());
  	display_category(vector<int>::iterator());
  	display_category(list<int>::iterator());	
  	display_category(forward_list<int>::iterator());  
  	display_category(deque<int>::iterator());

  	display_category(set<int>::iterator());
  	display_category(map<int,int>::iterator());
  	display_category(multiset<int>::iterator());
  	display_category(multimap<int,int>::iterator());
  	display_category(unordered_set<int>::iterator());
  	display_category(unordered_map<int,int>::iterator());
  	display_category(unordered_multiset<int>::iterator());
  	display_category(unordered_multimap<int,int>::iterator());	  
	    	
  	display_category(istream_iterator<int>());
  	display_category(ostream_iterator<int>(cout,""));
}															 
}