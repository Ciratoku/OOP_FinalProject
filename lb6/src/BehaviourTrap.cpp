#include "include/BehaviourTrap.h"
#include "include/board.h"

void BehaviourTrap::operator-(Player& player) 
{
    board& Field = board::GetInstance();

    iterator it = Field.begin();
    it = it + 2 + 6 * 7;
    (*it)->setType(PLAYER);
    player.setCoord(2,6);
}
