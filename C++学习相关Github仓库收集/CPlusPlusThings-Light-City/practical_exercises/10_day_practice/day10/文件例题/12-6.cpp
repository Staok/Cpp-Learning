//12-6.cpp
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    fstream ioFile;
    ioFile.open("./a.dat",ios::out);
    ioFile<<"����"<<"  "<<76<<" "<<98<<" "<<67<<endl;	//L3
    ioFile<<"����"<<"  "<<89<<" "<<70<<" "<<60<<endl;
    ioFile<<"��ʮ"<<"  "<<91<<" "<<88<<" "<<77<<endl;
    ioFile<<"�ƶ�"<<"  "<<62<<" "<<81<<" "<<75<<endl;
    ioFile<<"����"<<"  "<<90<<" "<<78<<" "<<67<<endl;
    ioFile.close();
    ioFile.open("./a.dat",ios::in|ios::binary);
    char name[10];
    int chinese,math,computer;
    cout<<"����\t"<<"Ӣ��\t"<<"��ѧ\t"<<"�����\t"<<"�ܷ�"<<endl; 
    ioFile>>name;										
    while(!ioFile.eof())	{								
        ioFile>>chinese>>math>>computer;					
        cout<<name<<"\t"<<chinese<<"\t"<<math<<"\t"<<computer<<"\t"<<chinese+math+computer<<endl;		
        ioFile>>name;
    }
    ioFile.close();										
    system("pause");
    return 0;
}
