#ifndef __CMDDRAWFIELD_H__
#define __CMDDRAWFIELD_H__

#include "Command.h"

class CmdDrawField : public Command 
{
public:
    void execute(GameSettings* _gamesettings) const override;
};

#endif // __CMDDRAWFIELD_H__