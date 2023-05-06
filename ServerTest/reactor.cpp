#include <stdint.h>
#include <unistd.h>
#include <map>
#include "reactor.h"

//实例化单例
Reactor Reactor::reactor;
Reactor& Reactor::get_instacne() {
	return reactor;
}
Reactor::Reactor() {
	impl = new ReactorImplementation();
}
Reactor::~Reactor() {
	if (impl) {
		delete impl;
	}
}
int Reactor::regist(EventHandle* handle, Event evt) {
	return impl->regist(handle, evt);
}
void Reactor::remove(EventHandle* handle) {
	return impl->remove(handle);
}
void Reactor::event_loop(int timeout) {
	impl->event_loop(timeout);
}