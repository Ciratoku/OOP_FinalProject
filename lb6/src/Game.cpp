#include "include/Game.h"

#include <conio.h>

#include "include/LoadExp.h"

void Game::start() 
{
    _start_cmd->execute(_game_settings);
    _draw_cmd->execute(_game_settings);
    unsigned char KEY;
    while(_game_settings->gameOver() != true)
    {
        KEY = _getch();
        if(KEY == 's')
            save();
        else if(KEY == 'l')
        {
            load();
        }
        _game_settings->setKey(KEY);
        _movecmd->execute(_game_settings);
        _draw_cmd->execute(_game_settings);
    }
    _endgame_cmd->execute(_game_settings);
}

void Game::save() 
{
    Save _save;
    _save.save();
}

void Game::load() 
{
    Load _load;
    try
    {
        _load.load();
    }
    catch(const LoadExp& e)
    {
        //gotoxy(7, 1);
        std::cout << e.What();
        _load.PrevState();
    }
}

std::ostream& operator<< (std::ostream &out, const Game &game);
