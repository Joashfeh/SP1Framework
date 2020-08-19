#pragma once
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

void generateMap(Map& map, Player& plr); // init map for level, player spawnpoint on the map
void spawnEnemies(Map& map);