#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <fcntl.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#include "ListenHandler.h"
#include "reactor.h"
#include "socketHandler.h"

ListenHandle::ListenHandle() :listenfd(-1) {

}
ListenHandle::~ListenHandle() {
	if (listenfd != -1) {
		close(listenfd);
	}
}
void ListenHandle::read_handle() {
	int fd = accept(listenfd, NULL, NULL);
	Reactor& r = Reactor::get_instacne();
	std::cout << "新的连接：" << fd << std::endl;
	r.clientfds.push_back(fd);
	SocketHandle* h = new SocketHandle(fd);
	setNonBlocking(h->get_handle());
	r.regist(h, ReadEvent);

}
bool ListenHandle::listen(int port) {
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cout << "Listen Error" << std::endl;
		return false;
	}
	struct sockaddr_in sockAddr;
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(port);
	sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(listenfd, (sockaddr*)&sockAddr, sizeof(sockAddr)) < 0) {
		std::cout << "bind Error" << std::endl;
		return false;
	}
	setNonBlocking(listenfd);
	if (::listen(listenfd, 10) < 0) {
		std::cout << "listen error" << std::endl;
		return false;
	}
	std::cout << "服务器开启成功" << std::endl;
	return true;
}
void ListenHandle::write_handle(){}
void ListenHandle::error_handle(){}
//将监听socket设置为非阻塞版本
void ListenHandle::setNonBlocking(int fd) {
	int op = fcntl(fd, F_GETFL);
	op = op | O_NONBLOCK;
	fcntl(fd, op);
}
