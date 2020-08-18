#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::setenemystats(Map type)
{
	switch (type.floor)
	{
	case ONE: // SAMPLE CASE
		HP = 15;
		Damage = 10;
		Defence = 5;
	default:
		// Default case | Should'nt be called
		break;
	}
}

Enemy::~Enemy()
{
}
