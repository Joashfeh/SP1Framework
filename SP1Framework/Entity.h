#pragma once
#include "Position.h"
class Entity
{
public:
	int HP, Damage;
	Position Pos;

	Entity();
	~Entity();
	virtual void Attack(Entity* ptrEntity) = 0;
	virtual void Defend() = 0;
	int getHP();
	void setPos(int r, int c);
	Position getPos();
};
