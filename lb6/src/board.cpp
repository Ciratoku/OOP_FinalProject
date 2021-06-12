#include "include/board.h"

board& board::GetInstance()
{
	static board instance;
	return instance;
}

Player& board::getPlayer() 
{
	return player;
}

void board::initialize()
{
	//static EnemyCellFactory enemies;
	
	static GunCellFactory guns;
	static MedCellFactory meds;
	//Entrance
	arr[0] = new cell();
	arr[0]->setType(PLAYER);
	//Exit
	arr[ROW*COL - 1] = new cell();
	arr[ROW*COL - 1]->setType(EXIT);
	//Block
	arr[5] = new cell();
	arr[5]->setType(BLOCK);
	arr[7] = new cell();
	arr[7]->setType(BLOCK);
	arr[8] = new cell();
	arr[8]->setType(BLOCK);
	arr[15] = new cell();
	arr[15]->setType(BLOCK);
	arr[22] = new cell();
	arr[22]->setType(BLOCK);
	arr[37] = new cell();
	arr[37]->setType(BLOCK);
	arr[38] = new cell();
	arr[38]->setType(BLOCK);
	arr[40] = new cell();
	arr[40]->setType(BLOCK);
	arr[41] = new cell();
	arr[41]->setType(BLOCK);
	arr[45] = new cell();
	arr[45]->setType(BLOCK);
	//Enemies
	arr[12] = new cell();
	arr[12]->setType(ENEMY);
	attack1.setCoord(5, 1);
	
	arr[23] = new cell();
	arr[23]->setType(ENEMY);
	takegun.setCoord(2, 3);

	arr[32] = new cell();
	arr[32]->setType(ENEMY);
	trap.setCoord(4, 4);

	arr[43] = new cell();
	arr[43]->setType(ENEMY);
	attack2.setCoord(1, 6);
	
	//GUN
	arr[14] = guns.make_cell();
	arr[14]->setStrategy(new PickGunStrategy);
	//MED
	arr[6] = meds.make_cell();
	arr[6]->setStrategy(new PickMedStrategy);
	for(int i = 1; i < ROW*COL - 1; i++)
	{
		if(arr[i] == nullptr)
			arr[i] = new cell();
	}
}

iterator<cell*> board::begin()
{
	return iterator(arr);
}

iterator<cell*> board::end()
{
	return iterator(arr + ROW * COL);
}

//operators

board::board(const board& other) //copy constructor
{
	for (int i = 0, j = 0; i < ROW * COL; ++i, ++j)
		this->arr[i] = other.arr[j];
}

board::board(board&& other) noexcept //move constructor
{
	for (int i = 0, j = 0; i < ROW * COL; ++i, ++j)
			this->arr[i] = other.arr[j];
		for (int i = 0; i < ROW * COL; ++i)
		{
			other.arr[i]->setType(ORDINARY);
		}
}

board& board::operator=(const board& other) //copy operator
{
	if (this == &other)
			return *this;
		for (int i = 0, j = 0; i < ROW * COL; ++i, ++j)
			this->arr[i] = other.arr[j];
		return *this;
}

board& board::operator=(board&& other) noexcept //move operator
{
	if (this == &other)
			return *this;
		for (int i = 0, j = 0; i < ROW * COL; ++i, ++j)
			this->arr[i] = other.arr[j];
		for (int i = 0; i < ROW * COL; ++i)
		{
			//other.arr[i] = cell(); ?
			other.arr[i]->setType(ORDINARY);
		}
		return *this;
}