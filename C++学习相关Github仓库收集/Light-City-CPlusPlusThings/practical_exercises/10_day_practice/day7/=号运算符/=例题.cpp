//����ch.cppi
#include <iostream>
using namespace std;
class X{
public:
	X &operator = (const X & x) 
	{cout << "a:"; return *this;};
};
int main ()
{
	X obj1, obj2, obj3;
	obj1 = obj2;          //�������ء�=��
	obj1.operator= (obj2); //�������ء�=��
	obj1 = obj2 = obj3;    //�������ء�=��
    system("pause");
}
