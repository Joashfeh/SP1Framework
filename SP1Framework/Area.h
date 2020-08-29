#pragma once
#include <iostream>

class Area {
public:
	unsigned short flags;
	char           area[16][16];

	Area();
	Area(unsigned short flags, int doorSize, int roomType);

	void loadMap(int terrainNo);
};

