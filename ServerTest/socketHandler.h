#pragma once
#include "EventHandler.h"
class SocketHandle : public EventHandle {
public:
	SocketHandle(int fd);
	virtual ~SocketHandle();

	virtual int get_handle() const;
	virtual void read_handle();
	virtual void write_handle();
	virtual void error_handle();
private:
	int socketfd;
	char* buf;
	static const int MAX_SIZE = 1024;

};