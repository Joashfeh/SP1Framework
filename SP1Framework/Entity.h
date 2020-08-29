#pragma once
#include "Position.h"
#include "colours.h"
#include "Framework/console.h"	

class Entity
{
public:
	COLOURS  renderColour;
	Position Pos;

	int      HP, Damage, Defense;
	int      gold;
	double   frameTimer;

	int      total_stats_points;
	char     special_defence; // For enemies only
	bool     boss;

	Entity();
	~Entity();
	virtual void Attack(Entity* ptrEntity, Console& g_Console, int turn) = 0;
	//virtual void Defend() = 0;
	int getHP();
	void setPos(int r, int c);
	Position getPos();
};
