#pragma once
#include <list>
#include <cstdio>
#include <exception>
#include <pthread.h>
#include "locker.h"
class task {
public:
	//一个无返回值，任意参数的指针函数
	void (*taskCallback)(void* arg);
	void* user_data;
	task(void(*callback)(void* arg), void* data)
	{
		taskCallback = callback;
		user_data = data;
	}
	void run() {
		taskCallback(user_data);
		delete this;
	}
};

class threadpool {
public :
	threadpool(int thead_number = 4, int max_requests = 1000);
	~threadpool();
	bool append(void (*taskCallback)(void* arg),void* args);
private:
	static void* worker(void* arg);
	void run();
private:
	int m_thread_number;
	int m_max_requests;
	pthread_t* m_threads;			// 线程池数组，大小为   m_thread_number
	std::list<task*> m_workqueue;	//任务数组
	locker m_queuelocker;			//保护请求队列的互斥锁
	sem m_queuestat;				//是否有任务需要处理
	bool m_stop;					//是否结束进程
};

threadpool::threadpool(int thread_number, int max_requests) : m_thread_number(thread_number), m_max_requests(max_requests), m_stop(false), m_threads(NULL) {
	if ((thread_number <= 0) || (max_requests <= 0))
	{
		throw std::exception();
	}
	m_threads = new pthread_t[m_thread_number];
	if (!m_threads) {
		throw std::exception();
	}
	//创建线程
	for (int i = 0; i < thread_number; i++)
	{
		printf("创建了线程 %d",i);
		if (pthread_create(m_threads + i, NULL, worker, this) != 0) {
			delete[] m_threads;
			throw std::exception();
		}
		if (pthread_detach(m_threads[i])) {
			delete[] m_threads;
			throw std::exception();
		}
	}
}

threadpool :: ~threadpool() {
	delete[] m_threads;
	m_stop = true;
}

bool threadpool::append(void(*c)(void* arg),void* args) {

	m_queuelocker.lock();
	if (m_workqueue.size() > m_max_requests) {
		m_queuelocker.unlock();
		return false;
	}
	task* request = new task(c,args);
	m_workqueue.push_back(request);
	m_queuelocker.unlock();
	m_queuestat.post();
	return true;
}

void* threadpool :: worker(void* arg) {
	threadpool* pool = (threadpool*)arg;
	pool->run();
	return pool;
}

void threadpool ::run() {
	while (!m_stop) {
		m_queuestat.wait();
		m_queuelocker.lock();
		if (m_workqueue.empty()) {
			m_queuelocker.unlock();
			continue;
		}
		task* request = m_workqueue.front();
		m_workqueue.pop_front();
		m_queuelocker.unlock();
		if (!request) {
			continue;
		}
		request->run();
	}
}


