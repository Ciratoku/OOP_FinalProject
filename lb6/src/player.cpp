#include "include/Player.h"

void Player::setHP(short HP) 
{
    this->HP = HP;
}

void Player::setDMG(short dmg) 
{
    this->damage = dmg;
    //this->model = 'R';
}

short Player::getDMG() 
{
    return this->damage;
}

short Player::getHP() const
{
    return this->HP;
}

int Player::getCoordX() 
{
    return coord.x;
}

int Player::getCoordY() 
{
    return coord.y;
}

void Player::setCoord(int x, int y) 
{
    coord.x = x;
    coord.y = y;
}

char Player::getModel() 
{
    return this->model;
}

void Player::setModel(char s) 
{
    model = s;
}

//operator+
Player& Player::operator+(cell* Cell) 
{
    if(Cell->getStrategy() != nullptr)
    {
        Cell->getStrategy()->DoAlgorithm(Cell, this);
    }  
	return *this;
}

std::ostream& operator<< (std::ostream &out, const Player &p) 
{
    if(p.getHP() > 0)
        out << "Player is alive\n";
    else
        out << "Player is dead\n"; 
}
