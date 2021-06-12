#ifndef __ENEMYOBSERVER_H__
#define __ENEMYOBSERVER_H__

#include "Observer.h"

class EnemyObserver : public Observer 
{
public:
    void update(const char* new_str) override;
};

#endif // __ENEMYOBSERVER_H__