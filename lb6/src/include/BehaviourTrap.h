#ifndef __BEHAVIOURTRAP_H__
#define __BEHAVIOURTRAP_H__

#include "Behaviour.h"

class BehaviourTrap : public Behaviour
{
public:
    void operator-(Player& player) override;
};

#endif // __BEHAVIOURTRAP_H__