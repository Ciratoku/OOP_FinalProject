#include "include/CmdDrawField.h"

void CmdDrawField::execute(GameSettings* _gamesettings) const 
{
    _gamesettings->drawField();
}