//https://www.cnblogs.com/yongdaimi/p/9565996.html

#include <iostream>

class Person
{
public:
    Person();
    ~Person();

    int getAge() const; 
    int getCallingTimes() const;
    void test(){}; //注意加不加；编译器都不会报错

private:
    int age;
    char* name;
    float score;
    mutable int m_nums; 
};


Person::Person()
{
    m_nums = 0;
}

Person::~Person(){}

int Person::getAge() const
{
    std::cout << "Calling the method" << std::endl;
    m_nums++;
    //age = 4;
    return age;
}

int Person::getCallingTimes() const
{
    return m_nums;
}

int main()
{
    Person* person = new Person();
    for(int i = 0; i < 10; ++i)
    {
        person->getAge();
    }
    std::cout << "getAge()方法被调用了" << person->getCallingTimes() << "次" << std::endl;
    delete person;

    return 0;
}