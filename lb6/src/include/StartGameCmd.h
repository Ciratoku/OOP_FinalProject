#ifndef __STARTGAMECMD_H__
#define __STARTGAMECMD_H__

#include "Command.h"

class StartGameCmd : public Command 
{
public:
    void execute(GameSettings* _gamesettings) const override;
};

#endif // __STARTGAMECMD_H__