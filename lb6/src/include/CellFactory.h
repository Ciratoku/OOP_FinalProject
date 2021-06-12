#pragma once
#include "cell.h"

class CellFactory
{
public:
	virtual cell* make_cell() = 0;
	virtual ~CellFactory() = default;
};
