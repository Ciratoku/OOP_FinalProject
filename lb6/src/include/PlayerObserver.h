#ifndef __PLAYEROBSERVER_H__
#define __PLAYEROBSERVER_H__

#include "Observer.h"

class PlayerObserver : public Observer 
{
public:
    void update(const char* new_str) override;
};

#endif // __PLAYEROBSERVER_H__