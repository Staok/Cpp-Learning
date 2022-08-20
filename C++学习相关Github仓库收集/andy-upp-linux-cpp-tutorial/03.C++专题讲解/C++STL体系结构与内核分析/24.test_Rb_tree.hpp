#include <set>
#include <functional>
#include <iostream>
namespace jj31
{
void test_Rb_tree()
{
	//G2.9 vs. G2.9 : 
	  //rb_tree => _Rb_tree, 
	  //identity<> => _Identity<>
	  //insert_unique() => _M_insert_unique()
	  //insert_equal() => _M_insert_equal()
		 
	cout << "\ntest_Rb_tree().......... \n";
     
	_Rb_tree<int, int, _Identity<int>, less<int>> itree;
	cout << itree.empty() << endl;  //1
	cout << itree.size() << endl;   //0

	itree._M_insert_unique(3);
	itree._M_insert_unique(8);
	itree._M_insert_unique(5);
	itree._M_insert_unique(9);
	itree._M_insert_unique(13);
	itree._M_insert_unique(5);  //no effect, since using insert_unique().
	cout << itree.empty() << endl;  //0
	cout << itree.size() << endl;   //5
	cout << itree.count(5) << endl; //1

	itree._M_insert_equal(5);
	itree._M_insert_equal(5);
	cout << itree.size() << endl;   //7, since using insert_equal().
	cout << itree.count(5) << endl; //3       
}															 
}