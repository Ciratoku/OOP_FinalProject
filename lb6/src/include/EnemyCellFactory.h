#pragma once

#include "enemy_cell.h"
#include "CellFactory.h"


class EnemyCellFactory : CellFactory
{
public:
	cell* make_cell() override
	{
		return new enemy_cell();
	}
};
