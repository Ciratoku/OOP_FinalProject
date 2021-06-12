#include "include/enemy_cell.h"


short enemy_cell::getHP() 
{
    return this->HP;
}


short enemy_cell::getDamage() 
{
    return this->damage;
}


void enemy_cell::die() 
{
    this->damage = 0;
    this->HP = 0;
}



