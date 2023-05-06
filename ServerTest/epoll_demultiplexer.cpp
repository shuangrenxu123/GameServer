#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include "event.h"
#include "EventHandler.h"
#include "event_demultiplexer.h"
#include "epoll_demultiplexer.h"
const int EpollDemultiplexer::MAX_EVENT = 1024;
EpollDemultiplexer::EpollDemultiplexer() :epoll_fd(-1){
	epoll_fd = epoll_create(MAX_EVENT);
	events.resize(MAX_EVENT);
}
EpollDemultiplexer::~EpollDemultiplexer() {
	if (epoll_fd != -1)
	{
		close(epoll_fd);
	}
}
int EpollDemultiplexer::wait_event(std::map<int, EventHandle*>& handlers, int timeout) {
	//将就绪的事件填充到events数组中。并返回就绪数量
	int num = epoll_wait(epoll_fd, &events[0], MAX_EVENT, timeout);
	for (int i = 0; i < num; i++)
	{
		EventHandle* handler = (EventHandle*)events[i].data.ptr;
		//如果是读事件
		if (events[i].events & EPOLLIN) {
			handler->read_handle();
		}
		//写事件,当该缓冲区未满的时候会一直被触发
		else if (events[i].events & EPOLLOUT) {
			handler->write_handle();
		}
		if (events[i].events & (EPOLLHUP | EPOLLERR)) {
			handler->error_handle();
		}
	}
	return num;
}

int EpollDemultiplexer::regist(EventHandle* handle, Event evt) {
	epoll_event ev;
	ev.data.ptr = (void*)handle;
	if (evt & ReadEvent) {
		ev.events | EPOLLIN;
		ev.events | EPOLLOUT;
	}
	if (evt & WriteEvent) {
		ev.events | EPOLLOUT;
	}
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, handle->get_handle(), &ev) != 0) {
		//该fd 并没有注册进 epoll中
		if (errno == ENOENT)
		{
			if (0 != epoll_ctl(epoll_fd, EPOLL_CTL_ADD, handle->get_handle(), &ev))
			{
				printf("epoll_ctrl add error : %s\n", strerror(errno));
				return -errno;
			}
		}
	}
	return 0;
}
int EpollDemultiplexer::remove(int handle) {
	struct epoll_event ev;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, handle, &ev)) {
		printf("epoll_ctrl del error : %s\n", strerror(errno));
		return -errno;
	}
	return 0;
}