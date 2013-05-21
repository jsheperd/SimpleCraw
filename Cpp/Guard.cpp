#include "Guard.h"

CGuard::CGuard(CMutex * pMutex) {
	m_pMutex = pMutex;
	m_pMutex->Lock();
}

CGuard::~CGuard() {
	m_pMutex->Unlock();
}
