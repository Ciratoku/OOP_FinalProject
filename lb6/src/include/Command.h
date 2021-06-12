#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "GameSettings.h"

class Command 
{
public:
    Command() = default;
    virtual ~Command() = default;
    virtual void execute(GameSettings* _gamesettings) const = 0;
};

#endif // __COMMAND_H__