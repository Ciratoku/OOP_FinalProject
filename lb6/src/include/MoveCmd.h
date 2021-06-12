#ifndef __MOVECMD_H__
#define __MOVECMD_H__

#include "Command.h"

class MoveCmd : public Command 
{
public:
    void execute(GameSettings* _gamesettings) const override;
};

#endif // __MOVECMD_H__