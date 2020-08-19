#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::setenemystats(Map type)
{
	for (int a = 0; a < enemycount; a++)
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
}

Enemy::~Enemy()
{
}
