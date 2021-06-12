#pragma once

#include "Player.h"
#include "med_cell.h"

class PickMedStrategy : public Strategy 
{
    void DoAlgorithm(cell* medcell, Player* player) override
    {
        //med_cell* ptr = new med_cell();
		med_cell* ptr = (med_cell*)medcell;
		player->setHP(player->getHP() + ptr->getHP());
		delete ptr->getStrategy();
		ptr->setStrategy(nullptr);
		medcell->setType(ORDINARY);
    }
};
