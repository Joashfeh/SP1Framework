#pragma once
#include <string>
#include "Map.h"
#include "Entity.h"

class Enemy : public Entity
{
public:

	std::string enemy_name;

	//const int enemycount = 3; // Max 3 mobs per level <- should be static
	static int enemyCount;
	bool inRange;
	int pattern_selection;
	int ability_selection;
	int heal_rate; // Used for ability 5
	int enemy_no;
	bool boss;

	int enemyType;

	Enemy();
	void Attack(Entity* ptrEntity, Console& g_Console, int turn);
	Enemy loadEnemy(int level, int get_i); // Load current enemy for level.
	//int return_enemy_count(); //Getter for enemycount
	~Enemy();
};
