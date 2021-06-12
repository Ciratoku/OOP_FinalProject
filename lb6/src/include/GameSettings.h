#ifndef __GAMESETTINGS_H__
#define __GAMESETTINGS_H__

#include "board.h"
#include "StateGame.h"

enum Keys{UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75};

class GameSettings
{
public:
GameSettings()
{
    
}
~GameSettings()
{

}

void setState(StateGame* gamestate);

void drawField();
void startGame();
void endGame();

void move();
void setKey(char KEY);

bool gameOver();
void checkLog(CellType celltype);

private:
StateGame* state;
bool isGameOver;
board& Field = board::GetInstance();
LogPub log_pub;
char key;
};

#endif // __GAMESETTINGS_H__