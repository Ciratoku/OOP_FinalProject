#include "include/MoveCmd.h"

void MoveCmd::execute(GameSettings* _gamesettings) const 
{
    _gamesettings->move();
}