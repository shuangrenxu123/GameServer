#pragma once
#include "event.h"
#include "EventHandler.h"
#include "reactor_impl.h"
#include "event_demultiplexer.h"
#include <vector>
class ReactorImplementation;
class Reactor {
public:
	std::vector<int> clientfds;
	static Reactor& get_instacne();
	int regist(EventHandle* handle, Event evt);
	void remove(EventHandle* handle);
	void event_loop(int timeout = 0);
private:
	Reactor();
	~Reactor();
	Reactor(const Reactor&);
	static Reactor reactor;
	// 具体实现类
	ReactorImplementation* impl;
};

