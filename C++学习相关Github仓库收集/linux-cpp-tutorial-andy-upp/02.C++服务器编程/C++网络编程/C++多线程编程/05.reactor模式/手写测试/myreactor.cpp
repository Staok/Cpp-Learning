#include "myreactor.h"
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <list>
#include <errno.h>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <unistd.h>

#define min(a,b) ((a <= b)? (a): (b))

CMyReactor::CMyReactor()
{

}

CMyReactor::~CMyReactor()
{
    
}