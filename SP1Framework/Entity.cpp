#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

int Entity::getHP()
{
	return HP;
}

void Entity::setPos(int r, int c)
{
	Pos.row = r;
	Pos.col = c;
}

Position Entity::getPos()
{
	return Pos;
}
