#pragma once

#include "med_cell.h"
#include "CellFactory.h"

class MedCellFactory : CellFactory
{
public:
	cell* make_cell() override
	{
		return new med_cell();
	}
};
