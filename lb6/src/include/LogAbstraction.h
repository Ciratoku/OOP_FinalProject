#ifndef __LOGABSTRACTION_H__
#define __LOGABSTRACTION_H__

#include "Observer.h"

class LogAbstraction 
{
public:
    LogAbstraction(Observer* new_observer);
    virtual void addLog(const char* new_str) const;
    virtual ~LogAbstraction() = default;
private:
    Observer* observer;
};

#endif // __LOGABSTRACTION_H__