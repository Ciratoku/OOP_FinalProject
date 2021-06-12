#ifndef __GAME_H__
#define __GAME_H__

#include "GameSettings.h"
#include "StartGameCmd.h"
#include "MoveCmd.h"
#include "EndGameCmd.h"
#include "CmdDrawField.h"
#include "Save.h"
#include "Load.h"

class Game 
{
public:
    Game()
    {
        _start_cmd = new StartGameCmd();
        _movecmd = new MoveCmd();
        _endgame_cmd = new EndGameCmd();
        _draw_cmd = new CmdDrawField();
        _game_settings = new GameSettings();
    }
    ~Game()
    {
        delete _start_cmd;
        delete _movecmd;
        delete _endgame_cmd;
        delete _draw_cmd;
        delete _game_settings;
    }
    void start();
    void save();
    void load();
private:
    StartGameCmd* _start_cmd;
    MoveCmd* _movecmd;
    EndGameCmd* _endgame_cmd;
    CmdDrawField* _draw_cmd;
    GameSettings* _game_settings;
    friend std::ostream& operator<< (std::ostream &out, const Game &game);
};

#endif // __GAME_H__