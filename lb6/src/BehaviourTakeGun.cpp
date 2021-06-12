#include "include/BehaviourTakeGun.h"
#include "include/board.h"

void BehaviourTakeGun::operator-(Player& player) 
{
    if(player.getDMG() > 0)
    {
        player.setDMG(0);
        player.setModel('P');
    }
    else
    {
        player.setHP(player.getHP() - 30);
    }
}
