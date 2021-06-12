#pragma once

#include "Player.h"
#include "gun_cell.h"

class PickGunStrategy : public Strategy 
{
public:
    void DoAlgorithm(cell* guncell, Player* player) override
    {
        //gun_cell* ptr = new gun_cell();
		gun_cell* ptr = (gun_cell*)guncell;
		player->setDMG(ptr->getDamage());
		player->setModel('R');
		delete ptr->getStrategy();
		ptr->setStrategy(nullptr);
		guncell->setType(ORDINARY);
    }
};
