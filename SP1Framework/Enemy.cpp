#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int Enemy::enemyCount = 0;

Enemy::Enemy()
{
}

void Enemy::Attack(Entity* ptrEntity)
{
}

void Enemy::setenemystats(LEVEL f, int get_b) //
{
	int line_no = 0;
	string enemy_file_extract;
	ifstream read;
	//Reference: https://stackoverflow.com/questions/26288145/how-to-read-a-specific-line-from-file-using-fstream-c
	switch (f)
	{
	case ONE: // SAMPLE CASE | Tutorial level 1 | JAN

		switch (get_b)
		{
		case 1: //Dummy1

			// First part sets health
			read.open("Enemy_data/level_01/health_data.txt");

			while (line_no != 0 && getline(read, enemy_file_extract))
			{
				++line_no;
			}

			if (line_no == 0) 
			{
				// sLine contains that line in the file.
			}
			else 
			{
				// The file contains fewer than said number of lines.
			}

			read.close(); // Closes file

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
