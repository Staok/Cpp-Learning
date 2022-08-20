
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

class Person{
    public:
        Person(){}
        Person(char *name,char *id,int math,int chinese,int english){
            strcpy(Name,name);
            strcpy(Id,id);
            Math=math;
            Chinese=chinese;
            English=english;
            Sum=Math+Chinese+English;
        }

        void display(){
            cout<<Name<<"\t"<<Id<<"\t"<<Math<<"\t"<<Chinese<<"\t"<<English<<"\t"<<Sum<<endl;
        }
    private:
        char Name[20];
        char Id[20];
        int Math;
        int Chinese;
        int English;
        int Sum;
};

int main(int argc, char const *argv[])
{
    char ch;
    char Name[20],Id[20];
    int Math,Chinese,English;
    fstream ioFile;
    ioFile.open("d:/per.dat",ios::out|ios::app);
    cout<<"---------����ѧ��������Ϣ----------\n";
    do{
        cout<<"������������";
        cin>>Name;
        cout<<"���������֤�ţ�";
        cin>>Id;
        cout<<"��������ѧ�ɼ���";
        cin>>Math;
        cout<<"�����뺺��ɼ���";
        cin>>Chinese;
        cout<<"������Ӣ��ɼ���";
        cin>>English;
        Person per(Name,Id,Math,Chinese,English);
        ioFile.write((char *)&per,sizeof(per));
        cout<<"���Ƿ����������(Y/y)  ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    ioFile.close();
    ioFile.open("d://per.dat",ios::in);
    Person p;
    ioFile.read((char*)&p,sizeof(p));
    vector<Person> v;
    vector<Person>::iterator vt;
    while(!ioFile.eof()){
        v.push_back(p);
        ioFile.read((char*)&p,sizeof(p));
    }
    ioFile.close();
    cout<<"---------���������Ϣ-----------"<<endl;
    for(vt=v.begin();vt!=v.end();vt++){
        (*vt).display();
    }
    system("pause");
    return 0;
}
