#pragma once
#include "Position.h"
#include "colours.h"

class Entity
{
public:
	COLOURS renderColour;

	int HP, Damage, Defense;
	double frameTimer;
	Position Pos;

	Entity();
	~Entity();
	virtual void Attack(Entity* ptrEntity) = 0;
	//virtual void Defend() = 0;
	int getHP();
	void setPos(int r, int c);
	Position getPos();
};
