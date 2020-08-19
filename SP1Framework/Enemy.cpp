#include "Enemy.h"
#include <fstream>



int Enemy::enemyCount = 0;

Enemy::Enemy()
{
}

void Enemy::Attack(Entity* ptrEntity)
{
}

void Enemy::setenemystats(LEVEL f, int get_b) //
{
	std::string enemy_file_extract;
	switch (f)
	{
	case ONE: // SAMPLE CASE | Tutorial level 1 | JAN

		switch (get_b)
		{
		case 1: //Dummy1
			enemy_file_extract = "Enemy_data/level_01";
			break;
		case 2: //Dummy2
			break;
		case 3: //Dummy3
			break;
		default:
			break;
		}

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
