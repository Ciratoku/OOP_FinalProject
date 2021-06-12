#ifndef __STATEENEMYTURN_H__
#define __STATEENEMYTURN_H__

#include "StateGame.h"

class GameStateEnemy : public StateGame 
{
public:
    void turn() override;
};

#endif // __STATEENEMYTURN_H__