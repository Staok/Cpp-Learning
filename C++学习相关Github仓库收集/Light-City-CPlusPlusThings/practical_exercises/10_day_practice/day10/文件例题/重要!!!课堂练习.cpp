#include<iostream>
#include<fstream>
//������һ���ܹ�����������͵Ķ�̬����
#include<vector>
#include<cstring>
using namespace std;
class Person{
    private:
        char name[20];
        char id[18];
        int age;
        char addr[20];
    public:
        Person(){}
        Person(char *n,char *pid,int Age,char* Addr){
            strcpy(name,n);
            strcpy(id,pid);
            age=Age;
            strcpy(addr,Addr);
        }
        void display(){
            cout<<name<<"\t"<<id<<"\t"<<age<<"\t"<<addr<<endl;
        }
};
int main(int argc, char const *argv[])
{
    vector<Person> v;
    vector<Person>::iterator pos;//����һ����������������vector���������ã���������ָ��vector������Ԫ�� 
    char ch;
    ofstream out("d:/person.dat",ios::out|ios::app|ios::binary);
    char Name[20],ID[18],Addr[20];
    int Age;
    cout<<"------������˵���------"<<endl<<endl;
    do{
        cout<<"������ ";
        cin>>Name;
        cout<<"���֤�ţ� ";
        cin>>ID;
        cout<<"���䣺 ";
        cin>>Age;
        cout<<"��ַ�� ";
        cin>>Addr;
        Person per(Name,ID,Age,Addr);
        out.write((char*)&per,sizeof(per));
        cout<<"Enter another Person(y/n)?";
        cin>>ch;
    }while(ch=='y');
    out.close();
    ifstream in("d:/person.dat",ios::in|ios::binary);	//L9
    Person s;
    in.read((char*)&s,sizeof(s));		
    while(!in.eof()){							       
        v.push_back(s);						       
        in.read((char*)&s,sizeof(s));			
    }								 
    cout<<"\n---------���ļ��ж���������--------"<<endl<<endl;//L15
    pos=v.begin();						
    for(pos=v.begin();pos!=v.end();pos++)				        
        (*pos).display();				

    system("pause");
    return 0;
}
