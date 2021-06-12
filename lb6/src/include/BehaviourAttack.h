#ifndef __BEHAVIOURATTACK_H__
#define __BEHAVIOURATTACK_H__

#include "Behaviour.h"

class BehaviourAttack : public Behaviour
{
    public:
    void operator-(Player& player) override;
};

#endif // __BEHAVIOURATTACK_H__