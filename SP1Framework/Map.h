#pragma once
#include "Area.h"
#include <stdlib.h>
#include <time.h>

class Map {
public:
	int   floor;
	Area* map[6][6]; // 4x4 map array but 6x6 with a bunch of empty areas around it for no broken camera :D
	char  fullMap[96][96];
	char  display[96][196];

	Map();
	~Map();

	const void generateDungeon(int floor, int floorType); // floorType: 0 for Tutorial, 1 for normal dungeons, 2 for bosses

};

