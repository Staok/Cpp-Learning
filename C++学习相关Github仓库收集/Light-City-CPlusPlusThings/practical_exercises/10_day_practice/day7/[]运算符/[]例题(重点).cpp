//Eg8-9.cpp
#include <iostream>
#include <cstring>
using namespace std;
struct Person{                		//ְ��������Ϣ�Ľṹ
		double salary;
		char *name;
};
class SalaryManaege{
		Person *employ;          	 //���ְ����Ϣ������
		int max;                  		//�����±��Ͻ�
		int n;                    		//�����е�ʵ��ְ������
public:
	SalaryManaege(int Max=0){
		max=Max;
		n=0;
		employ=new Person[max];
	}
    double &operator[](char *Name) {       	//����[]����������
		Person *p;
		for(p=employ;p<employ+n;p++)   
			//������ڴ���   	
			if(strcmp(p->name,Name)==0) 
				return p->salary;
		//�������������
		p=employ + n++; 
		p->name=new char[strlen(Name)+1];
		strcpy(p->name,Name);
		p->salary=0;
		return p->salary;
	}

	void display(){      								
		for(int i=0;i<n;i++)
			cout<<employ[i].name<<"   "<<employ[i].salary<<endl;
		}
};
int main(){
    SalaryManaege s(3);
    s["����"]=2188.88;
    s["��˹"]=1230.07;
    s["����"]=3200.97;
    cout<<"����\t"<<s["����"]<<endl;          cout<<"��˹\t"<<s["��˹"]<<endl;
    cout<<"����\t"<<s["����"]<<endl;
  
    cout<<"-------��Ϊdisplay�����--------\n\n";
    s.display();
    system("pause");
}

