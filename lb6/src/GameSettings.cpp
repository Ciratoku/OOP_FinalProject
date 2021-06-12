#include "include/GameSettings.h"
#include "include/gotoxy.h"

void GameSettings::startGame() 
{
    log_pub.sub(new PlayerObserver, _player);
	log_pub.sub(new GameObserver, _game);
	log_pub.sub(new ItemObserver, _item);
	log_pub.sub(new EnemyObserver, _enemy);
	log_pub.Notify(_game, "started");
    Field.initialize();
}

void GameSettings::endGame() 
{
    log_pub.Notify(_game, "ended");
}

void GameSettings::checkLog(CellType celltype) 
{
        static short line = 8;
        gotoxy(0, line++);
		if(celltype == ENEMY)
		{
			if(Field.player.getHP() <= 0)
			{
				log_pub.Notify(_enemy, "killed the player");
				log_pub.Notify(_player, "is dead");
				//log_pub.Notify(_game, "ended");
                isGameOver = true;
			}
			else if(Field.player.getDMG() > 0)
			{
				log_pub.Notify(_player, "killed an enemy");
				log_pub.Notify(_enemy, "is dead");
			}
            else
            {
                log_pub.Notify(_player, "escaped an enemy");
				log_pub.Notify(_enemy, "is still alive");
            }
		}
		else if(celltype == GUN)
		{
			log_pub.Notify(_player, "took the gun");
			log_pub.Notify(_item, "Gun");
		}
		else if(celltype == MED)
		{
			log_pub.Notify(_item, "Medkit");
		}
		else if(celltype == EXIT)
		{
			//log_pub.Notify(_game, "ended");
            isGameOver = true;
		}
        else if(celltype == ORDINARY)
        {
            log_pub.Notify(_player, "steped on an ordinary cell");
        }
        else if(celltype == BLOCK)
        {
            log_pub.Notify(_player, "hit a block");
        }
}

void GameSettings::move() 
{
    if(key == LEFT or key == RIGHT or key == UP or key == DOWN)
    {
    iterator itr = Field.begin();
    itr = itr + Field.player.getCoordX() + Field.player.getCoordY() * 7;
    iterator prev = itr;
    int x_cpy = Field.player.getCoordX();
    int y_cpy = Field.player.getCoordY();
    if(key == LEFT and Field.player.getCoordX() > 0)
    {
        Field.player.setCoord(Field.player.getCoordX() - 1, Field.player.getCoordY());
        itr--;
    }
    else if(key == RIGHT and Field.player.getCoordX() < 6)
    {
        Field.player.setCoord(Field.player.getCoordX() + 1, Field.player.getCoordY());
        itr++;
    }
    else if(key == UP and Field.player.getCoordY() > 0)
    {
        Field.player.setCoord(Field.player.getCoordX(), Field.player.getCoordY() - 1);
        itr = itr - 7;
    }
    else if(key == DOWN and Field.player.getCoordY() < 6)
    {
        Field.player.setCoord(Field.player.getCoordX(), Field.player.getCoordY() + 1);
        itr = itr + 7;
    }
    CellType type = (*itr)->getType();
    if(type == BLOCK)
    {
        itr = prev;
        Field.player.setCoord(x_cpy, y_cpy);
    }
    else if(type == ENEMY)
    {
        if(Field.player.getCoordX() == 5 and Field.player.getCoordY() == 1)
        {
            Field.attack1.getBehaviour() - Field.player;
            Field.player.setCoord(x_cpy, y_cpy);
        }
        else if(Field.player.getCoordX() == 2 and Field.player.getCoordY() == 3)
        {
            Field.takegun.getBehaviour() - Field.player;
            Field.player.setCoord(x_cpy, y_cpy);
        }
        else if(Field.player.getCoordX() == 4 and Field.player.getCoordY() == 4)
        {
            Field.trap.getBehaviour() - Field.player;
            (*prev)->setType(ORDINARY);
        }
        else
        {
            Field.attack2.getBehaviour() - Field.player;
            Field.player.setCoord(x_cpy, y_cpy);
        }
        if(Field.player.getDMG() > 0)
        {
            (*itr)->setType(ORDINARY);
        }       
    }
    else
    {
        Field.player + (*itr);
        (*prev)->setType(ORDINARY);
        (*itr)->setType(PLAYER);
    }
    checkLog(type);
    }
}

void GameSettings::drawField() 
{
    int line = 0;
    gotoxy(0,1);
	for (iterator<cell*> itr = Field.begin(); itr != Field.end(); itr++)
	{
		if((*itr)->getType() == EXIT)
			std::cout << "B";
		else if((*itr)->getType() == GUN)
			std::cout << "G";
		else if((*itr)->getType() == MED)
			std::cout << "A";
		else if((*itr)->getType() == BLOCK)
			std::cout << "0";
		else if((*itr)->getType() == ENEMY)
			std::cout << "*";
        else if((*itr)->getType() == PLAYER)
        {
            std::cout << Field.player.getModel();
        }
		else 
			std::cout << " ";			
		std::cout << "|";
		line++;
		if (line % 7 == 0)
			std::cout << "\n";
	}
}

void GameSettings::setKey(char KEY) 
{
    this->key = KEY;
}

bool GameSettings::gameOver() 
{
    return isGameOver;
}
