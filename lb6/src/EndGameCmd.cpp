#include "include/EndGameCmd.h"

void EndGameCmd::execute(GameSettings* _gamesettings) const 
{
    _gamesettings->endGame();
}