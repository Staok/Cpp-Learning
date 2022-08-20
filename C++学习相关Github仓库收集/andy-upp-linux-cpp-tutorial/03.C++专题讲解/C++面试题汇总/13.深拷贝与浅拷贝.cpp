//https://blog.csdn.net/caoshangpa/article/details/79226270

 #include <iostream>
 using namespace std;

 class Student
 {
public:
    Student();
    Student(const Student& s);
    ~Student();
    

private:
    int num;
    char* name;
 };

 Student::Student()
 {
     name = new char(20);
     cout << "Student" << endl;
 }

Student::Student(const Student& s)
{
    //把在构造函数里面做的复制操作在拷贝构造函数再做一遍
    //但是需要另外分配内存，把源对象的内容拷贝到目的对象
    name = new char(20);
    memcpy(name, s.name, sizeof(s.name));
    cout << "copy Studnet" << endl;
    
}

 Student::~Student()
 {
     cout << "~Student" << endl;
     delete name;
     name = NULL;
 }

 int main()
 {
     
    Student s1;
    Student s2(s1);
    
    return 0;
 }