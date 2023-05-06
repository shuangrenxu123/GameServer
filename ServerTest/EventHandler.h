#pragma once
class EventHandle {
public :
	EventHandle(){}
	virtual ~EventHandle() {}
	virtual int get_handle() const = 0;
	virtual void read_handle() = 0;
	virtual void write_handle() = 0;
	virtual void error_handle() = 0;
};