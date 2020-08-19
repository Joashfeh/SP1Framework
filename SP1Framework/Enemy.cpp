#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::setenemystats(LEVEL f, int get_a)
{
	switch (f)
	{
	case ONE: // SAMPLE CASE

<<<<<<< HEAD
		switch (enemycounthere)
		{
		case 1: //Dummy1
			break;
		default:
			break;
		}
		HP = 15;
		Damage = 10;
		Defence = 5;
=======

		
>>>>>>> 03d7a3a6dec2dae0d5ad9dc4ea46128769c251be
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
