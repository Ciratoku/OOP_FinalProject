#ifndef __ENDGAMECMD_H__
#define __ENDGAMECMD_H__

#include "Command.h"

class EndGameCmd : public Command 
{
public:
    void execute(GameSettings* _gamesettings) const override;
};

#endif // __ENDGAMECMD_H__