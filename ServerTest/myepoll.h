#pragma once
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <vector>
#include "threadPool.h"
class MyEpoll {

public:
    MyEpoll();
    ~MyEpoll();
private:
    int socketfd;
    sockaddr_in seraddr;
    int epollfd;
    char errMsg[256];
    std::vector<int> clientfds;
public:
    bool start(int port, bool isblock = false);
    int get_SocketFd();
    bool do_epoll();
    void add_event(int fd, int state);
    void remove_event(int fd, int state);
    void mod_event(int fd, int state);

    void handle_events(epoll_event* events, int num, char* buff, int& bufflen);
    bool handle_accept();

    bool do_read(int fd, char* buff, int& bufflen);
    bool do_write(int fd, char* buff, int& bufflen);

};