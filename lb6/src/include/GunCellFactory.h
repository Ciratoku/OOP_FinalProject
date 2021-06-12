#pragma once

#include "gun_cell.h"
#include "CellFactory.h"

class GunCellFactory : CellFactory
{
public:
	cell* make_cell() override
	{
		return new gun_cell();
	}
};
