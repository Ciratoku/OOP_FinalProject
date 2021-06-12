#pragma once

#include <iostream>
#include "Strategy.h"

enum CellType{ ORDINARY, ENTRANCE, BLOCK, ENEMY, GUN, MED, EXIT, PLAYER }; /*обычная, вход, выход*/

class cell
{
private:
	CellType type; 
	Strategy* strategy;
public:
	cell()
	{
		type = ORDINARY;
		strategy = nullptr;
	}
	Strategy* getStrategy();
	void setStrategy(Strategy* strategy);
	CellType getType();
	void setType(CellType type);
};

