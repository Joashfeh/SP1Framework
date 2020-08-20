#include "Enemy.h"
#include "Player.h"
#include "enemyDeclare.h"
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

void Enemy::setenemystats(int get_a) //
{
	string enemyDir;
	enemyDir = "Enemy_Data/level_";
	enemyDir += to_string(get_a + 1);


	// Set Health
	string enemyDirHP = enemyDir;
	enemyDirHP += "/health_data.txt";

	std::ifstream enemyDataHP(enemyDirHP, std::ios::in);
	if (!enemyDataHP)
		return;

	string enemyset;
	getline(enemyDataHP, enemyset);

	// STOI: https://www.geeksforgeeks.org/converting-strings-numbers-cc/
	HP = stoi(enemyset);


	// Set Damage
	string enemyDirDamage = enemyDir;
	enemyDirDamage += "/attack_data.txt";

	std::ifstream enemyDataDamage(enemyDirDamage, std::ios::in);
	if (!enemyDataDamage)
		return;

	enemyset = " "; // Clear enemyset
	getline(enemyDataDamage, enemyset);

	Damage = stoi(enemyset);

	enemyDataHP.close();
	enemyDataDamage.close();
}

Enemy Enemy::loadEnemy(int level, int get_a)
{
	return Enemy();
}

/*int Enemy::return_enemy_count()
{
	return enemycount;
}*/

Enemy::~Enemy()
{
}
