#pragma once
#include "Framework\console.h"
#include "Player.h"
#include "Map.h"

enum MAPTILE {
	EMPTYTILE = '9',
	WALL = '1',
	SPAWNPOINT = '2',
	ENEMYSPAWN = '3'
};

void renderMap(Console& g_Console, Player& plr, Map& map);           // renders the map to the buffer first