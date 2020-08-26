#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include "renderCharacterDamage.h"
#include "enemyAttackPatterns.h"

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

void Enemy::Attack(Entity* ptrEntity, Console& g_Console) {

	float damage = this->Damage;

	// Pattern determinant switch
	switch (pattern_selection)
	{
	default:
		break;
	}

	if (((Player*)ptrEntity)->isDefend) {
		damage = (float)damage;
		damage *= 0.7;
		damage = (int)damage;
	}

	if (ptrEntity->Defense == 0)
		ptrEntity->HP -= damage;

	if (ptrEntity->Defense != 0) {
		ptrEntity->HP -= damage * 0.5;
		ptrEntity->Defense -= damage * 0.5;
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