#pragma once

#include "iterator.h"
#include "Player.h"

#include "LogPub.h"

#include "GunCellFactory.h"
#include "MedCellFactory.h"
#include "EnemyCellFactory.h"

#include "FightStrategy.h"
#include "PickGunStrategy.h"
#include "PickMedStrategy.h"

#include "ItemObserver.h"
#include "GameObserver.h"
#include "PlayerObserver.h"
#include "EnemyObserver.h"

#include "BehaviourTrap.h"
#include "BehaviourTakeGun.h"
#include "BehaviourAttack.h"

#include "Enemy.h"

#define ROW 7
#define COL 7

class board
{
private:
	board() = default;
	cell* arr[ROW * COL];
	Player player;
	Enemy<BehaviourAttack> attack1;
	Enemy<BehaviourTrap> trap;
	Enemy<BehaviourTakeGun> takegun;
	Enemy<BehaviourAttack> attack2;
	//operators
	board(const board& other); //copy constructor

	board(board&& other) noexcept; //move constructor

	board& operator=(const board& other); //copy operator

	board& operator=(board&& other) noexcept; //move operator
	
	friend class GameSettings;

public:
	static board& GetInstance();
	Player& getPlayer();
	void print();
	void initialize();
	iterator<cell*> begin();
	iterator<cell*> end();
};