#pragma once
#include "Map.h"
#include "Player.h"


struct Enemies {
    Position pos;
};


void generateMap(Map& map, Player& plr);
void spawnEnemies(Map& map);