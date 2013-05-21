#include "Guard.h"

// CMutex
CMutex::CMutex(){
	InitializeCriticalSection( &m_tCriticalSection );
}

CMutex::~CMutex(){
	DeleteCriticalSection( &m_tCriticalSection );
}

void CMutex::Lock(){
	EnterCriticalSection( &m_tCriticalSection );
}

void CMutex::Unlock(){
	LeaveCriticalSection( &m_tCriticalSection );
}


//CGuard
CGuard::CGuard(CMutex * pMutex) {
	m_pMutex = pMutex;
	m_pMutex->Lock();
}

CGuard::~CGuard() {
	m_pMutex->Unlock();
}
