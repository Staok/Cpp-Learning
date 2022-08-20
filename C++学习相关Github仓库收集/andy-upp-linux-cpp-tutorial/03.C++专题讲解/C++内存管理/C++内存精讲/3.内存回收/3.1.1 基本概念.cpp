//
// Created by 李光辉 on 2020/12/27.
//

class Base
{
public:
    static Type s_object ;
}
class Derived1 : public Base / / 公共继承
{
……// other data
}
class Derived2 : public Base / / 公共继承
{
… …// other data
}
Base example ;
Derivde1 example1 ;
Derivde2 example2 ;
example.s_object = …… ;
example1.s_object = …… ;
example2.s_object = …… ; 
