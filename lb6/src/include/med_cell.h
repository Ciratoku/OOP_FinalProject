#pragma once


#include "cell.h"

class med_cell:public cell
{
public:
	med_cell()
	{
		setType(MED);
		HP = 30;
	}
	short getHP();
private:
	short HP;
};