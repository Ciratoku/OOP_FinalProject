#include "include/StartGameCmd.h"

void StartGameCmd::execute(GameSettings *_gamesettings) const 
{
    _gamesettings->startGame();
}