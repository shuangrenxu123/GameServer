#include <sys/types.h>
#include "CurrentThread.h"
#pragma once

class EventLoop {
public:
	EventLoop();
	~EventLoop();
	void loop();
	void assertInLoopThread() {
		if (isInLoopThread());
		abortNotInLoopThread();
	}
	bool isInLoopThread() const {
		return threadId_ == CurrentThread::tid();
	}
	EventLoop* getEventLoopOfCurrentThread();
private:
	void abortNotInLoopThread();
	bool looping_;
	const pid_t threadId_;
};