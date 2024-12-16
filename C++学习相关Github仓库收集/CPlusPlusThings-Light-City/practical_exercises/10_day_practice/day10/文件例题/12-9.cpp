//Eg12-12.cpp
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Employee{
private:
    int number ,age;
    char name[20];
    double sal;
public:
    Employee(){}
    Employee(int num,char* Name,int Age, double Salary){
        number=num;
        strcpy(name,Name);
        age=Age;
        sal=Salary;
    }
    void display(){
        cout<<number<<"\t"<<name<<"\t"<<age<<"\t"<<sal<<endl;
    }
};

int main(){
    ofstream out("D:/Employee.dat",ios::out);	//�����������ļ�
    Employee e1(1,"����",23,2320);
    Employee e2(2,"����",32,3210);
    Employee e3(3,"����",34,2220);
    Employee e4(4,"����",27,1220);
    out.write((char*)&e1,sizeof(e1));		//��e1,e2,e3,e4˳��д���ļ�
    out.write((char*)&e2,sizeof(e2));
    out.write((char*)&e3,sizeof(e3));
    out.write((char*)&e4,sizeof(e4));

     //����Ĵ��뽫e3�������壩�������Ϊ40��   
    Employee e5(3,"����",40,2220);
    out.seekp(3*sizeof(e1));		//ָ�붨λ����3����ʼΪ0�������ݿ�
    out.write((char*)&e5,sizeof(e5));	//��e5д����3�����ݿ�λ�ã�����e3
    out.close();			//�ر��ļ�
    system("pause");
}