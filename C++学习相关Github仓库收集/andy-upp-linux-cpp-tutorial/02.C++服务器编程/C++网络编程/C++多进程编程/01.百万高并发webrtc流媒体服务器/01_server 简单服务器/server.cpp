//
// Created by andy on 2019/10/2.
//

//引入C++头文件
#include <iostream>
//引入C语言头文件

//引入本目录下头文件加""
#include "server.h"


namespace avdance {

//实现构造函数
Server::Server(){
        std::cout << "construct..." << std::endl;
    }
//实现析构函数
Server::~Server(){
    std::cout << "destruct..." << std:endl;
}

//实现成员函数run
void Server::run(){
    while(1){
        std::cout << "running..." << std::endl;
        //每隔一秒休息一段时间，usleep是C语言中的函数，C++如果要访问C语言中的函数，需要加::
        ::usleep(1000000);
    }
}
}