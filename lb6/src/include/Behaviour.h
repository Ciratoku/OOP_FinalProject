#ifndef __BEHAVIOUR_H__
#define __BEHAVIOUR_H__

class Player;

class Behaviour 
{
public:
    virtual void operator-(Player& player) = 0;
};

#endif // __BEHAVIOUR_H__