#include<iostream>
using namespace std;

int main() {
    //逻辑非
	int a = 10;

	cout << !a << endl; // 0

	cout << !!a << endl; // 1

    //逻辑与
    int a_ = 10;
	int b_ = 10;

	cout << (a_ && b_) << endl;// 1

	a_ = 10;
	b_ = 0;

	cout << (a_ && b_) << endl;// 0 

	a_ = 0;
	b_ = 0;

	cout << (a_ && b_) << endl;// 0

    //逻辑或
    int _a = 10;
	int _b = 10;

	cout << (_a || _b) << endl;// 1

	_a = 10;
	_b = 0;

	cout << (_a || _b) << endl;// 1 

	_a = 0;
	_b = 0;

	cout << (_a || _b) << endl;// 0




	return 0;
}