#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include "renderCharacterDamage.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;


int Enemy::enemyCount = 0;

Enemy::Enemy() 
{
	enemyCount++;

	inRange = false;
	enemy_name = " ";
	HP = 0;
	Damage = 0;
	Defense = 0;
}

void Enemy::Attack(Entity* ptrEntity, Console& g_Console, int turn) {

	float damage = this->Damage;
	//### SWITCH CASES FOR PATTERNS AND ABILITIES ###

	srand(time(0)); // Generate a random number less than MSP for deciding chance for every turn.
	float chance = rand() % total_stats_points;

	int damage_boost;
	int chance_boost;

	// Pattern determinant switch
	switch (pattern_selection)
	{
		//attack 0 | Does not attack | Usually not called
	case 0:
		//0 Damage | Usually not called as all enemies by default have pattern set to 1
		damage = 0;
		break;

		//attack 1 | Attack only
	case 1:
		// Case 1 is left blank so that damage is unaltered
		break;

		//attack 2 | No attack chance 
	case 2:
		if (chance < damage)
		{
			damage = 0;
			break;
		}
		else
		{
			break;
		}

		//attack 3 | Double damage
	case 3:
		if (chance < damage)
		{
			damage *= 2;
			break;
		}
		else
		{
			break;
		}

	case 4:
		//attack 4 | Overcharge: Sacrifice some health to boost attack | Random amount from 1 to enemy's max damage.
		damage_boost = rand() % Damage;
		chance_boost = rand() % damage_boost;
		if (chance_boost == damage_boost)
		{
			HP -= damage_boost;
			damage += damage_boost;
			break;
		}

	case 5:
		//attack 5 | Independent Damage boost by doubling | Chance formula: 1 / Damage
		damage_boost = Damage * 2;
		chance_boost = rand() % Damage;
		if (chance_boost == Damage)
		{
			damage = damage_boost;
			break;
		}

	default:
		break;
	}

	chance = rand() % total_stats_points; // Generate new chance number for enemy to decide to use ability or to attack.

	switch (ability_selection)
	{
	case 0:
		// No abilities
		break;
	case 1:
		// Full block chance with chance formula: defence / total_stats_points

	case 2:
		// Regen lost health by 20% max health.
		HP += HP * 0.2;
		break;

	case 3:
		// Deflection

	default:
		break;
	}

	//### END OF SWITCH CASES ###


	if (((Player*)ptrEntity)->isDefend) {
		damage = (float)damage;
		damage *= 0.7;
		damage = (int)damage;
	}

	if (ptrEntity->Defense == 0)
		ptrEntity->HP -= damage;

	if (ptrEntity->Defense != 0) {
		//ptrEntity->HP -= floor(damage / ptrEntity->Defense);
		ptrEntity->Defense -= damage;
	}

	if (ptrEntity->Defense < 0)
		ptrEntity->Defense = 0;

	if (ptrEntity->HP < 0)
		ptrEntity->HP = 0;

	triggerRenderPlayerDamage();
}

Enemy Enemy::loadEnemy(int level, int get_i)
{
	string enemyDir;
	enemyDir = "Enemy_Data/level_";
	enemyDir += to_string(level);


	// Set Health //
	string enemyDirHP = enemyDir;
	enemyDirHP += "/health_data.txt";


	// Open the file
	std::ifstream enemyDataHP(enemyDirHP, std::ios::in);
	if (!enemyDataHP)
		return Enemy();

	string enemyset;
	int line_no = 0;

	// Load data
	while (line_no != get_i + 1 && getline(enemyDataHP, enemyset))
	{
		line_no++;
		if (line_no == get_i + 1)
		{
			HP = stoi(enemyset);
		}
	}

	// Set Damage //

	string enemyDirDamage = enemyDir;
	enemyDirDamage += "/attack_data.txt";


	// Open the file
	std::ifstream enemyDataDamage(enemyDirDamage, std::ios::in);
	if (!enemyDataDamage)
		return Enemy();

	enemyset = " "; // Clear enemyset
	line_no = 0;

	// Load the file
	while (line_no != get_i + 1 && getline(enemyDataDamage, enemyset))
	{
		line_no++;
		if (line_no == get_i + 1)
		{
			Damage = stoi(enemyset);
		}
	}


	// Set Defence //

	string enemyDirDefence = enemyDir;
	enemyDirDefence += "/defence_data.txt";


	// Open the file
	std::ifstream enemyDataDefence(enemyDirDefence, std::ios::in);
	if (!enemyDataDefence)
		return Enemy();

	enemyset = " "; // Clear enemyset
	line_no = 0;

	// Load the file
	while (line_no != get_i + 1 && getline(enemyDataDefence, enemyset))
	{
		line_no++;
		if (line_no == get_i + 1)
		{
			Defense = stoi(enemyset);
		}
	}

	// Set Name //

	string enemyDirName = enemyDir;
	enemyDirName += "/name_data.txt";


	// Open the file
	std::ifstream enemyDataName(enemyDirName, std::ios::in);
	if (!enemyDataName)
		return Enemy();

	enemyset = " "; // Clear enemyset
	line_no = 0;

	// Load the file
	while (line_no != get_i + 1 && getline(enemyDataName, enemyset))
	{
		line_no++;
		if (line_no == get_i + 1)
		{
			enemy_name = enemyset;
		}
	}

	// Set Pattern_Selection //

	string enemyDirPattern = enemyDir;
	enemyDirPattern += "/pattern_data.txt";


	// Open the file
	std::ifstream enemyDataPattern(enemyDirPattern, std::ios::in);
	if (!enemyDataPattern)
		return Enemy();

	enemyset = " "; // Clear enemyset
	line_no = 0;

	// Load the file
	while (line_no != get_i + 1 && getline(enemyDataPattern, enemyset))
	{
		line_no++;
		if (line_no == get_i + 1)
		{
			pattern_selection = stoi(enemyset);
		}
	}

	// Set Ability_Selection //

	string enemyDirAbility = enemyDir;
	enemyDirAbility += "/defence_data.txt";


	// Open the file
	std::ifstream enemyDataAbility(enemyDirAbility, std::ios::in);
	if (!enemyDataAbility)
		return Enemy();

	enemyset = " "; // Clear enemyset
	line_no = 0;

	// Load the file
	while (line_no != get_i + 1 && getline(enemyDataAbility, enemyset))
	{
		line_no++;
		if (line_no == get_i + 1)
		{
			ability_selection = stoi(enemyset);
		}
	}

	total_stats_points = Damage + HP + Defense; // Sets total_stats_points

	enemyDataAbility.close();
	enemyDataPattern.close();
	enemyDataHP.close();
	enemyDataDamage.close();
	enemyDataDefence.close();
	return Enemy();
}

Enemy::~Enemy() {
	enemyCount--;
}