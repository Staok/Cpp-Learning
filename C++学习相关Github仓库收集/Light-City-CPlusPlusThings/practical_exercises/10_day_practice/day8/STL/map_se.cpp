#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(int argc, char const *argv[])
{
    string name[]={"����","����","������"};
    double salary[]={1200,2000,1450};
    map<string,double>sal;
    map<string,double>::iterator p;
    for(int i=0;i<3;i++){
        sal.insert(make_pair(name[i],salary[i]));
    }
    sal["tom"]=6156;
    sal["bob"]=5999;
    for(p=sal.begin();p!=sal.end();p++){
        cout<<p->first<<"\t"<<p->second<<endl;
    }
    string person;
    cout<<"���������Ա������:";
    cin>>person;
    int flag=1;
    for(p=sal.begin();p!=sal.end();p++)
        if(p->first==person){
            cout<<p->second<<endl;    
            flag=0; 
        }
    if(flag)
        cout<<"û���ҵ���Ӧ�Ľ����"<<endl; 

    cout<<"�����ɾ������Ա������:";
    cin>>person;
    map<string,double>::iterator it;
    it = sal.find(person);
    if(it!=sal.end()){
        cout<<"���ҳɹ���"<<(*it).first<<":"<<(*it).second<<endl;
        sal.erase(it);
        cout<<"ɾ���ɹ�"<<endl;
    }
    cout<<"ɾ����Ľ��Ϊ"<<endl;
    for(p=sal.begin();p!=sal.end();p++){
        cout<<p->first<<p->second<<endl;
    }

    system("pause");
    return 0;
}
