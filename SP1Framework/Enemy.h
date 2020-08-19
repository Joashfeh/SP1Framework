#pragma once
#include <string>
#include "Map.h"
#include "Entity.h"
using namespace std;

class Enemy : public Entity
{
public:
	//const int enemycount = 3; // Max 3 mobs per level

	Enemy();
	void Attack(Entity* ptrEntity);
	void setenemystats(LEVEL f, int get_a); // Sets enemy stats based on level and enemy type.
	//int return_enemy_count(); //Getter for enemycount
	~Enemy();
};

