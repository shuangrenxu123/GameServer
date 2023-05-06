#pragma once
#include "EventHandler.h"
//作为主线程的事件处理器,负责连接和注册等
class ListenHandle :public EventHandle {
public:
	ListenHandle();
	virtual ~ListenHandle();
	virtual int get_handle() const { return listenfd; }
	virtual void read_handle();
	virtual void write_handle();
	virtual void error_handle();

	bool listen(int port);
private :
	int listenfd;
	void setNonBlocking(int fd);
};