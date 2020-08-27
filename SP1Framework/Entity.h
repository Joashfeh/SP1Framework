#pragma once
#include "Position.h"
#include "colours.h"
#include "Framework/console.h"	

class Entity
{
public:
	COLOURS renderColour;

	int HP, Damage, Defense;
	double frameTimer;
	Position Pos;
	int gold;

	Entity();
	~Entity();
	virtual void Attack(Entity* ptrEntity, Console& g_Console, int turn) = 0;
	//virtual void Defend() = 0;
	int getHP();
	void setPos(int r, int c);
	Position getPos();
};
