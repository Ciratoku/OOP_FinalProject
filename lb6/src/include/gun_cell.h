#pragma once

#include "cell.h"

class gun_cell:public cell
{
public:
	gun_cell()
	{
		setType(GUN);
        damage = 30;
	}
	short getDamage();
private:
	short damage;
};
