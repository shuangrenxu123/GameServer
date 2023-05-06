#pragma once
#include <map>
#include "EventHandler.h"
#include "event_demultiplexer.h"
class ReactorImplementation {
public:
	ReactorImplementation();
	~ReactorImplementation();

	typedef std::map<int, EventHandle*>::iterator iterator;

	int regist(EventHandle* handle, Event evt);
	void remove(EventHandle* handle);
	void event_loop(int timeout = 0);
private:
	EventDemultiplexer* demultiplexer;
	std::map<int, EventHandle*> handlers;
};