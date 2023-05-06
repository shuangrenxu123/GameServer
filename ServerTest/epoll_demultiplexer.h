#pragma once
#include <vector>
#include <sys/epoll.h>
#include "event_demultiplexer.h"
class EpollDemultiplexer : public EventDemultiplexer {
public:
	EpollDemultiplexer();
	virtual ~EpollDemultiplexer();

	virtual int wait_event(std::map<int, EventHandle*>& handles, int timeout = 0);
	virtual int regist(EventHandle* handle, Event evt);
	virtual int remove(int handle);
private:
	static const int MAX_EVENT;
	int epoll_fd;
	std::vector<struct epoll_event> events;
};