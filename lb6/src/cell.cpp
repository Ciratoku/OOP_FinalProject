#include "include/cell.h"

void cell::setType(CellType type)
{
	this->type = type;
}

CellType cell::getType()
{
	return this->type;
}

Strategy* cell::getStrategy() 
{
	return this->strategy;
}

void cell::setStrategy(Strategy* strategy) 
{
	this->strategy = strategy;
}