#pragma once
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Position.h"

struct goldCrate {
	Position pos;
	int gold;
};

void generateMap(Map& map, Player& plr, Enemy* enemies[], goldCrate* crate, int floor); // init map for level, player spawnpoint on the map
void spawnEnemies(Map& map, Enemy* arr[]);