#include "socketHandler.h"
#include "reactor.h"
#include "EventHandler.h"
#include <map>
#include <string.h>
#include <unistd.h>
#include <iostream>

SocketHandle::SocketHandle(int fd) :socketfd(fd),buf(new char[MAX_SIZE])
{
	memset(buf, 0, MAX_SIZE);
}
SocketHandle::~SocketHandle() {
	close(socketfd);
	delete[] buf;
}
int SocketHandle::get_handle() const {
	return socketfd;
}
void SocketHandle::write_handle() {

}
void SocketHandle::read_handle() {
	int length = read(socketfd, buf, MAX_SIZE);
	if (length > 0) {
		Reactor& r = Reactor::get_instacne();
		for (std::vector<int>::iterator i = r.clientfds.begin(); i != r.clientfds.end(); i++)
		{
			write(*i, buf, length);
		}
		memcpy(buf, buf + length, MAX_SIZE - length);
	}
	else 
	{
		error_handle();
	}
}
void SocketHandle::error_handle() {
	Reactor& r = Reactor::get_instacne();
	std::cout << socketfd << "连接关闭" << std::endl;
	for (std::vector<int>::iterator i = r.clientfds.begin(); i != r.clientfds.end(); i++)
	{
		if (*i == socketfd) {
			r.clientfds.erase(i);
			break;
		}
	}
	std::cout << "当前连接剩余" << r.clientfds.size() << std::endl;
	r.remove(this);
	delete this;
}