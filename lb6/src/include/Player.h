#pragma once

#include "cell.h"

class Player
{
private:
	struct Coord
	{
		int x, y;
		Coord()
		{
			x = 0;
			y = 0;
		}
		~Coord()
		{
			x = 0;
			y = 0;
		}
		Coord(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	}coord;
	friend std::ostream& operator<< (std::ostream &out, const Player &p);
	short HP;
	short damage;
	char model = 'P';
public:
   	Player()
	{
		this->HP = 60;
		this->damage = 0;
	}
	~Player()
	{
		this->HP = 0;
		this->damage = 0;
	}
	Player& operator+(cell* Cell);
	void setHP(short HP);
	void setDMG(short dmg);
	short getDMG();
	short getHP() const;
	int getCoordX();
	int getCoordY();
	void setCoord(int x, int y);
	char getModel();
	void setModel(char s);
};
