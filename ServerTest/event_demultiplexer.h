#pragma once
#include <map>
#include "EventHandler.h"
#include "event.h"
class EventDemultiplexer {
public:
	EventDemultiplexer() {}
	virtual ~EventDemultiplexer() {}
	virtual int wait_event(std::map<int, EventHandle*>& handlers, int timeout = 0) = 0;
	virtual int regist(EventHandle* handle, Event evt) = 0;
	virtual int remove(int handle) = 0;
};