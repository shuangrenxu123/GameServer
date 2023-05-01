#ifndef LOCKER_H
#define LOCKER_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>
/// <summary>
/// 信号量类
/// </summary>
class sem {
	public:
		sem() {
			if (sem_init(&m_sem, 0, 0) != 0) {
				throw std::exception();
			}
		}
		~sem() {
			sem_destroy(&m_sem);
		}
		/// <summary>
		/// 等待信号量
		/// </summary>
		/// <returns></returns>
		bool wait() {
			return sem_wait(&m_sem);
		}
		/// <summary>
		/// 增加信号量
		/// </summary>
		/// <returns></returns>
		bool post() {
			return sem_post(&m_sem);
		}
	private :
		sem_t m_sem;
};
/// <summary>
/// 互斥锁类
/// </summary>
class locker {
private:
	pthread_mutex_t m_mutex;
public:
	locker() {
		if (pthread_mutex_init(&m_mutex, NULL) != 0) {
			throw std::exception();
		}
	}
	~locker() {
		pthread_mutex_destroy(&m_mutex);
	}
	bool lock() {
		return pthread_mutex_lock(&m_mutex);
	}
	bool unlock() {
		return pthread_mutex_unlock(&m_mutex);
	}
};
/// <summary>
/// 条件变量类
/// </summary>
class cond {
private:
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;
public :
	cond() {
		if (pthread_mutex_init(&m_mutex, NULL) != 0) {
			throw std::exception();
		}
		if (pthread_cond_init(&m_cond, NULL) != 0) {
			pthread_mutex_destroy(&m_mutex);
			throw std::exception();
		}
	}
	~cond() {
		pthread_mutex_destroy(&m_mutex);
		pthread_cond_destroy(&m_cond);
	}
	/// <summary>
	/// 等待条件变量
	/// </summary>
	/// <returns></returns>
	bool wait() {
		int ret = 0;
		pthread_mutex_lock(&m_mutex);
		ret = pthread_cond_wait(&m_cond, &m_mutex);
		pthread_mutex_unlock(&m_mutex);
	}
	/// <summary>
	/// 唤醒等待条件变量的线程
	/// </summary>
	/// <returns></returns>
	bool signal() {
		return pthread_cond_signal(&m_cond) == 0;
	}
};
#endif // !LOCKER_H

