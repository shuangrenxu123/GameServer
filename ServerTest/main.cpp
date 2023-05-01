#include <cstdio>
#include "myepoll.h"
#include <iostream>

int main()
{
    MyEpoll ser;
    ser.start(20000);
    ser.do_epoll();
    return 0;
}