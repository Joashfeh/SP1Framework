#pragma once
#include "Area.h"
#include <stdlib.h>
#include <time.h>

enum LEVEL {
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	ELEVEN = 11,
	TWELVE = 12
};

class Map {
public:
	LEVEL floor;
	Area* map[6][6]; // 4x4 map array but taken as 6x6 for camera tracking
	int fullMap[96][96]; // upscaled to display onto the screen ( 2 x 4 )
	int display[96][196];

	Map();
	Map(LEVEL f, int floorType); // floorType: 0 for Tutorial, 1 for normal dungeons, 2 for bosses
	~Map();

	void generateDungeon();

};

