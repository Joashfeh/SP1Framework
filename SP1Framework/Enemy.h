#pragma once
#include <string>
#include "Map.h"
#include "Entity.h"

using namespace std;

class Enemy : public Entity
{
public:

	//const int enemycount = 3; // Max 3 mobs per level <- should be static
	static int enemyCount;
	bool inRange;

	Enemy();
	void Attack(Entity* ptrEntity);
	//void setenemystats(int get_a); // Sets enemy stats based on level and enemy type.
	Enemy loadEnemy(int level, int get_i); // Load current enemy for level.
	//int return_enemy_count(); //Getter for enemycount
	~Enemy();
};
