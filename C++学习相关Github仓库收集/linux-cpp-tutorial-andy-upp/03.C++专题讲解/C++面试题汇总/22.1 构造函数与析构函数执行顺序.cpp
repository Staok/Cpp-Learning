//https://blog.csdn.net/qq_40024275/article/details/100527678

#include <iostream>
using namespace std;
class O{
public:
	O(){
		cout << "Constructor O" << endl;
	}
	~O(){
		cout << "Deconstructof O" << endl;
	}
};

class A:O{
public:
	A(){
		cout << "Constructor A" << endl;
	}
	~A(){
		cout << "Deconstructof A" << endl;
	}
};

class B{
public:
	B(){
		cout << "Constructor B" << endl;
	}
	~B(){
		cout << "Deconstructof B" << endl;
	}
};

class C{
public:
	C(){
		cout << "Constructor C" << endl;
	}
	~C(){
		cout << "Deconstructof C" << endl;
	}
};

class D{
public:
	D(){
		cout << "Constructor D" << endl;
	}
	~D(){
		cout << "Deconstructof D" << endl;
	}
};

class E{
public:
	E(){
		cout << "Constructor E" << endl;
	}
	~E(){
		cout << "Deconstructof E" << endl;
	}
};


class Test : E, D 
{
public:
	Test(){
		cout << "Constructor Test" << endl;
	}
	~Test(){
		cout << "Deconstructor Test" << endl;
	}

private:
    B b;
    A a;
};


int main()
{
    Test* t = new Test;
    delete t;
    return 0;
}

/*
Constructor E
Constructor D
Constructor B
Constructor O
Constructor A
Constructor Test
Deconstructor Test
Deconstructof A
Deconstructof O
Deconstructof B
Deconstructof D
Deconstructof E


*/