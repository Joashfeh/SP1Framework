#pragma once
#include <iostream>

class Area {
public:
	char area[16][16];
	unsigned short flags;

	Area();
	Area(unsigned short flags, int doorSize, int roomType);

	void display();
	void loadMap(int terrainNo);
};

