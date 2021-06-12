#ifndef __ENEMY_H__
#define __ENEMY_H__

template <class T>
class Enemy
{
public:
	Enemy()
	{
		HP = 30;
		damage = 30;
	}
	~Enemy()
	{
		HP = 0;
		damage = 0;
		coord.x = -1;
		coord.y = -1;
	}
	void setCoord(int x, int y)
	{
		coord.x = x;
    	coord.y = y;
	}
	friend std::ostream& operator<< (std::ostream &out, const Enemy &enemy)
	{
		if(enemy.getHP() > 0)
			out << "Enemy was killed\n";
		else
			out << "Enemy is still alive\n";
    	return out;
	}
	short getHP();
	short getDamage();
	void die();
	T getBehaviour()
	{
		return behaviour;
	}
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
	short HP;
	short damage;
	T behaviour;
};

#endif // __ENEMY_H__