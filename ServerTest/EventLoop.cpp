#include "EventLoop.h"
#include <cstddef>
#include <iostream>
//__thread 关键字可以让每个线程的值都不同
__thread EventLoop* t_loopInThisThread = 0;
EventLoop::EventLoop() : looping_(false),threadId_(CurrentThread::tid())
{
	if (t_loopInThisThread) {

	}
	else
	{
		t_loopInThisThread = this;
	}
}
EventLoop::~EventLoop() {
	t_loopInThisThread = NULL;
}
EventLoop* EventLoop::getEventLoopOfCurrentThread() {
	return t_loopInThisThread;
}
void EventLoop::loop() {
	assertInLoopThread();
	looping_ = true;
	std::cout << "EventLoop" << this << "stop loopping";
	looping_ = false;
}