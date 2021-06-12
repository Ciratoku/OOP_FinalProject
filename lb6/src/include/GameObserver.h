#ifndef __GAMEOBSERVER_H__
#define __GAMEOBSERVER_H__

#include "Observer.h"

class GameObserver : public Observer 
{
public:
    void update(const char* new_str) override;
};

#endif // __GAMEOBSERVER_H__