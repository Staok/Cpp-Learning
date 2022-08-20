/*
 * 练习3.16：编写一段程序，把练习3.13中vector对象的容量和其具体内容输出出来，检验你之前的回答是否正确，如果不对，回头重新学习3.3.1节（第87页）直到弄明白错在何处位置。
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

#define PRINT_VEC(vec) \
do { \
	cout << #vec << " has " << (vec).size() << " element(s):"; \
	for (auto it = (vec).cbegin(); it != (vec).cend(); ++it) \
		cout << " " << *it; \
	cout << endl; \
} while(0)

int main()
{
	vector<int> v1;						// 0个元素
	vector<int> v2(10);					// 10个元素，都是0
	vector<int> v3(10, 42);				// 10个元素，都是42
	vector<int> v4{10};					// 1个元素，10
	vector<int> v5{10, 42};				// 2个元素，10,42
	vector<string> v6{10};				// 10个元素，都是空string
	vector<string> v7{10, "hi"};		// 10个元素，都是字符串hi

	PRINT_VEC(v1);
	PRINT_VEC(v2);
	PRINT_VEC(v3);
	PRINT_VEC(v4);
	PRINT_VEC(v5);
	PRINT_VEC(v6);
	PRINT_VEC(v7);

	return 0;
}
