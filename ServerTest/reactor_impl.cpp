#include "event.h"
#include "EventHandler.h"
#include "event_demultiplexer.h"
#include "epoll_demultiplexer.h"
#include "reactor_impl.h"

ReactorImplementation::ReactorImplementation() {
	demultiplexer = new EpollDemultiplexer();

}
ReactorImplementation::~ReactorImplementation() {
	if (demultiplexer)
		delete demultiplexer;
}

int ReactorImplementation::regist(EventHandle* handle, Event evt) {
	return demultiplexer->regist(handle, evt);
}
void ReactorImplementation::remove(EventHandle* handler) {
	int handle = handler->get_handle();
	demultiplexer->remove(handle);
}
void ReactorImplementation::event_loop(int timeout) {
	demultiplexer->wait_event(handlers,timeout);
}