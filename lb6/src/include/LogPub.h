#ifndef __LOGPUB_H__
#define __LOGPUB_H__

#include "LogAbstraction.h"
#include <map>

enum Event
{
    _game, _player, _enemy, _item
};

class LogPub
{
public:
    void sub(Observer* observer, Event event);
    void unsub(Observer* observer);
    void Notify(Event event, const char* new_str);
    ~LogPub();
private:
    std::map<Observer*, Event> subscribers;
};

#endif // __LOGPUB_H__