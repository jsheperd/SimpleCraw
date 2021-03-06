#ifndef GUARD_H
#define GUARD_H

#include <windows.h>
#include "mutex.h"

// Usage:
//  CMutex m_InstanceMutex;
//  int instances = 0;
//	... 
//	{ critical section block begin
//  	CGuard guard(&m_InstanceMutex);
//
//   	instances = instances + 1;
//
//   	if (instances == 10){
//   	throw 1;
//  }

class CGuard {
	private:
 		CMutex * m_pMutex;
	public:
		CGuard(CMutex * pMutex);
  	~CGuard();
};

#endif /* GUARD_H */
