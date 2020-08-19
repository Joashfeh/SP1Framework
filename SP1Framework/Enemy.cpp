#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::setenemystats(Map level, int enemycounthere)
{
	switch (level.floor)
	{
	case ONE: // SAMPLE CASE

		switch (enemycounthere)
		{
		case 1: //Dummy1
			break;
		default:
			break
		}
		HP = 15;
		Damage = 10;
		Defence = 5;
	default:
		// Default case | Should'nt be called
		break;
	}
}

/*int Enemy::return_enemy_count()
{
	return enemycount;
}*/

Enemy::~Enemy()
{
}
