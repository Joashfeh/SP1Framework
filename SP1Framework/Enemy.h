#pragma once
#include <string>
#include "Map.h"
#include "Entity.h"
<<<<<<< HEAD
=======

>>>>>>> d3f7966d33c75aac626fca97a53548a0bc1fd2c7
class Enemy : public Entity
{
public:

	std::string enemy_name;

	//const int enemycount = 3; // Max 3 mobs per level <- should be static
	static int enemyCount;
	bool inRange;
	int pattern_selection;
	int ability_selection;
	int total_stats_points;

	Enemy();
	void Attack(Entity* ptrEntity, Console& g_Console, int turn);
	Enemy loadEnemy(int level, int get_i); // Load current enemy for level.
	//int return_enemy_count(); //Getter for enemycount
	~Enemy();
};
