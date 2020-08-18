#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::setenemystats(Map type)
{
	switch (type.floor)
	{
	case ONE:
		Enemy.setHP();
	default:
		break;
	}
}

Enemy::~Enemy()
{
}
