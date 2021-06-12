#ifndef __BEHAVIOURTAKEGUN_H__
#define __BEHAVIOURTAKEGUN_H__

#include "Behaviour.h"

class BehaviourTakeGun : public Behaviour
{
public:
    void operator-(Player& player) override;
};

#endif // __BEHAVIOURTAKEGUN_H__