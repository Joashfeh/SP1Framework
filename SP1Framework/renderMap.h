#pragma once
#include "game.h"

enum MAPTILE {
	EMPTYTILE = 0,
	WALL = 1,
	SPAWNPOINT = 2,
	ENEMYSPAWN = 3
};

void renderMap(Console& g_Console, Player& plr, Map& map);           // renders the map to the buffer first