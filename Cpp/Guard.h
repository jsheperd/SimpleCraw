#ifndef GUARD_H
#define GUARD_H


class CMutex {
private:
    CRITICAL_SECTION m_tCriticalSection;
public:
    void Lock();
    void Unlock();    
 };

class CGuard {
private:
     CMutex * m_pMutex;
public:
    CGuard(CMutex * pMutex) {
        m_pMutex = pMutex;
        m_pMutex->Lock();
        }
    ~CGuard() {
        m_pMutex->Unlock();
        }
    };



CMutex m_InstanceMutex;
int instances = 0;


// critical section
{
CGuard guard(&m_InstanceMutex);

instances = instances + 1;

if (instances == 10) ...
  throw 1;
}



#endif /* GUARD_H */

