#pragma once
#include "Enemy.h"
#include "Map.h"


Enemy* entity_ptrs[3][12]; // 2D array of enemies | 3 item columns for enemies on specific level and 12 rows for 12 levels

void enemyDeclare(Map& map);

//void loadEnemy();