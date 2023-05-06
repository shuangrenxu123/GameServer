#include <cstdio>
#include <iostream>
#include "ListenHandler.h"
#include "reactor.h"
#include "event.h"
int main()
{
	ListenHandle* handle = new ListenHandle();
	handle->listen(20000);
	Reactor& actor = Reactor::get_instacne();
	actor.regist(handle, ReadEvent);

	while (true)
	{
		//-1即不等待
		actor.event_loop(-1);
	}
	return 0;
}