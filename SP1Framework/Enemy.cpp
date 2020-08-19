#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::setenemystats(LEVEL f, int get_a) //
{
	switch (f)
	{
	case ONE: // SAMPLE CASE

		switch (f)
		{
		case 1: //Dummy1
			break;
		default:
			break;
		}
		HP = 15;
		Damage = 10;

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
