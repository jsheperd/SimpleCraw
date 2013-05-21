#ifndef MUTEX_H
#define MUTEX_H

#include <windows.h>
#include <Synchapi.h>

class CMutex {
	private:
		CRITICAL_SECTION m_tCriticalSection;
	public:
		CMutex();
		~CMutex();

		void Lock();
		void Unlock();    
};

#endif /* MUTEX_H */
