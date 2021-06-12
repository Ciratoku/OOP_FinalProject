#pragma once

#include "Strategy.h"
#include "enemy_cell.h"
#include "Behaviour.h"

class FightStrategy : public Strategy 
{
public:
    void DoAlgorithm(cell* enemycell, Player* player) override
    {
        //enemy_cell* ptr = new enemy_cell();
		enemy_cell* ptr = (enemy_cell*)enemycell;
		player->setHP(player->getHP() - ptr->getDamage());
		if(player->getDMG() != 0)
		{
			ptr->die();
			delete ptr->getStrategy();
			ptr->setStrategy(nullptr);
			enemycell->setType(ORDINARY);
		}
    }
};
