#include "myepoll.h"
#define Size 4096
MyEpoll::MyEpoll() {

	socketfd = 0;
	memset(&seraddr, 0, sizeof(seraddr));
}
MyEpoll::~MyEpoll() {

}
bool MyEpoll::start(int port, bool isblock) {
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd == -1) {
		std::cout << "创建监听失败" << std::endl;
		return false;
	}
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(port);
	seraddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(socketfd, (sockaddr*)&seraddr, sizeof(seraddr)) == -1)
	{
		std::cout << "绑定失败:" << errno << std::endl;
		return false;
	}
	if (listen(socketfd, 10) == -1) {
		std::cout << "监听失败:" << errno << std::endl;
		return false;
	}
	std::cout << "服务器开启成功:" << errno << std::endl;
	return true;
}

int MyEpoll::get_SocketFd()
{
	return socketfd;
}

bool MyEpoll::do_epoll()
{
	epoll_event events[100];
	int ret;
	char buff[Size];
	int bufflen = 0;
	epollfd = epoll_create(100);
	if (epollfd == -1) {
		std::cout << "创建epoll错误" << std::endl;
		return false;
	}
	add_event(socketfd, EPOLLIN);
	while (1) {
		//返回值为有多少个事件可以处理
		ret = epoll_wait(epollfd, events, 100, -1);
		handle_events(events, ret, buff, bufflen);
	}
	close(epollfd);
}

void MyEpoll::add_event(int fd, int state) {
	epoll_event event;
	event.events = state;
	event.data.fd = fd;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
}
void MyEpoll::remove_event(int fd, int state) {
	epoll_event event;
	event.events = state;
	event.data.fd = fd;
	epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &event);
}
void MyEpoll::mod_event(int fd, int state)
{
	struct epoll_event ev;
	ev.events = state;
	ev.data.fd = fd;
	epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &ev);
}
void MyEpoll::handle_events(epoll_event* events, int num, char* buff, int& bufflen)
{
	int fd;
	for (int i = 0; i < num; i++)
	{
		fd = events[i].data.fd;
		if ((fd == socketfd) && (events[i].events & EPOLLIN)) {
			handle_accept();
		}
		else if (events[i].events & EPOLLIN)
			do_read(fd, buff, bufflen);
		else if (events[i].events & EPOLLOUT)
			do_write(fd, buff, bufflen);
		else 
			close(fd);
	}
}
bool MyEpoll::handle_accept()
{
	int clientfd;
	sockaddr_in clientaddr;
	socklen_t	clientaddrlen = sizeof(clientaddr);
	clientfd = accept(socketfd, (sockaddr*)&clientaddr, &clientaddrlen);
	if (clientfd == -1) {
		std::cout << "连接失败" << std::endl;
		return false;
	}
	else
	{
		char msg[Size];
		std::cout << "连接成功：" << clientfd << std::endl;
		clientfds.push_back(clientfd);
		add_event(clientfd, EPOLLIN);
		return true;
	}
}
bool MyEpoll::do_read(int fd, char* buff, int& bufflen)
{
	bufflen = read(fd, buff, Size);
	if (bufflen == -1) {
		close(fd);
		remove_event(fd, EPOLLIN);
		return false;
	}
	else if (bufflen == 0) {
		close(fd);
		std::cout << fd << "连接关闭" << std::endl;
		for (std::vector<int>::iterator i =clientfds.begin(); i != clientfds.end(); i++)
		{
			if (*i == fd) {
				clientfds.erase(i);
				break;
			}
		}
		std::cout << "当前连接剩余" << clientfds.size() << std::endl;
		remove_event(fd, EPOLLIN);
		return true;
	}
	else {
		mod_event(fd, EPOLLOUT);
		for (std::vector<int>::iterator i = clientfds.begin(); i != clientfds.end(); i++)
		{
			do_write(*i, buff, bufflen);
		}
		memcpy(buff,buff+bufflen,Size-bufflen);
	}
	return true;
}
bool MyEpoll::do_write(int fd, char* buff, int& bufflen)
{
	int nwrite = write(fd, buff, bufflen);
	if (nwrite == -1) {
		std::cout << "写入错误" << std::endl;
		return false;
	}
	else if (nwrite == 0) {
		close(fd);
		remove_event(fd, EPOLLIN);
		return false;
	}
	else {
		char msg[Size];
		mod_event(fd, EPOLLIN);
		return true;
	}
}


