#pragma once
#include "Enemy.h"
#include "Map.h"


Enemy* entity_ptrs[3]; // 2D array of enemies | 3 item columns for enemies on specific level and 12 rows for 12 levels

void enemyDeclare(Map& map);
Enemy* get_ptr(int enemy); // Getter for getting an enemy stat on entity_ptrs.

//void loadEnemy();