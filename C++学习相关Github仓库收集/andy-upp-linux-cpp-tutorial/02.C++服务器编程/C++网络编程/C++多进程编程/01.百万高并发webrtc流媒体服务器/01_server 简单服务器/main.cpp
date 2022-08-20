
//
// Created by andy on 2019/11/19.
//
#include <iostream>
#include "server.h"



int main(int argc, char *argv[])
{
    //创造一个server对象
   avdance::Server* server = new avdance::Server();
    if(server){
        server->run();
    }
    return 0;
}