﻿#ifndef _CELL_HPP_
#define _CELL_HPP_

//SOCKET
#ifdef _WIN32
#define FD_SETSIZE      256
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<windows.h>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#else
#include<unistd.h> //uni std
#include<arpa/inet.h>
#include<string.h>

#define SOCKET int
#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)
#endif
//
#include"MessageHeader.hpp"
#include"CELLTimestamp.hpp"
#include"CELLTask.hpp"
//
#include<stdio.h>

//缓冲区最小单元大小
#ifndef RECV_BUFF_SZIE
#define RECV_BUFF_SZIE 10240
#define SEND_BUFF_SZIE RECV_BUFF_SZIE
#endif // !RECV_BUFF_SZIE

#endif // !_CELL_HPP_
