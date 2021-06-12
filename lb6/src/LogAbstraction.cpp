#include "include/LogAbstraction.h"

LogAbstraction::LogAbstraction(Observer* new_observer) 
{
    observer = new_observer;
}

void LogAbstraction::addLog(const char* str) const
{
    observer->update(str);
}