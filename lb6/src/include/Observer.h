#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "LogFile.h"

class Observer 
{
public:
    virtual ~Observer() = default;
    virtual void update(const char* new_str) = 0;
};

#endif // __LOGOBSERVER_H__