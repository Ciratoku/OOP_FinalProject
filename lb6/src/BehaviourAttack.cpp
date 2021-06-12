#include "include/BehaviourAttack.h"
#include "include/Player.h"

void BehaviourAttack::operator-(Player& player) 
{
    player.setHP(player.getHP() - 30);
}