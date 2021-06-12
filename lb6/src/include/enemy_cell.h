#pragma once

#include "cell.h"

class enemy_cell:public cell
{
public:
	enemy_cell()
	{
		setType(ENEMY);
		HP = 30;
		damage = 30;
	}
	short getHP();
	short getDamage();
	void die();
private:
	short HP;
	short damage;
};

