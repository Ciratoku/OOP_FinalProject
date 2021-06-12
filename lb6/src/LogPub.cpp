#include "include/LogPub.h"

void LogPub::sub(Observer* observer, Event event) 
{
    subscribers[observer] = event;
}

void LogPub::unsub(Observer* observer) 
{
    subscribers.erase(observer);
}

void LogPub::Notify(Event event, const char* new_str) 
{
    for (auto it : subscribers)
        if (it.second == event) 
        {
            LogAbstraction log_abstraction(it.first);
            log_abstraction.addLog(new_str);
        }
}

LogPub::~LogPub() 
{
    for (auto it : subscribers)
        delete it.first;
}