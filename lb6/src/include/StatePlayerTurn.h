#ifndef __STATEPLAYERTURN_H__
#define __STATEPLAYERTURN_H__

#include "StateGame.h"

class StatePlayerTurn : public StateGame 
{
public:
    void turn() override;
};

#endif // __STATEPLAYERTURN_H__