#include "Area.h"

Area::Area() {
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 16; k++) {
			area[i][k] = 0;
		}
	}
}

Area::Area(unsigned short flags, int doorSize, int roomType) {
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 16; k++) {
			area[i][k] = 9; // mobs can spawn
		}
	}

	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 16; k++) {
			if (i == 0 || i == 15) area[i][k] = 1;
			if (k == 0 || k == 15) area[i][k] = 1;
		}
	}

	if (roomType == 0) { // Spawn Room
		for (int i = 1; i < 15; i++) {
			for (int k = 1; k < 15; k++) {
				area[i][k] = 0;
			}
		}
		area[8][7] = 2;
	}

	if (roomType == 1) { // Normal Room

	}

	if (roomType == 2) { // Exit Room

	}

	if (doorSize == 1) {
		if (flags & 0b0001) { area[0][6] = 0; area[0][7] = 0; area[0][8] = 0; area[0][9] = 0; }; // top is open
		if (flags & 0b0010) { area[6][15] = 0; area[7][15] = 0; area[8][15] = 0; area[9][15] = 0; }; // right is open
		if (flags & 0b0100) { area[15][6] = 0; area[15][7] = 0; area[15][8] = 0; area[15][9] = 0; }; // bottom is open
		if (flags & 0b1000) { area[6][0] = 0; area[7][0] = 0; area[8][0] = 0; area[9][0] = 0; }; // left is open
	}

	if (doorSize == 2) {
		if (flags & 0b0001) { for (int i = 1; i < 14; i++) { area[0][i] = 0; } }; // top is open
		if (flags & 0b0010) { for (int i = 1; i < 14; i++) { area[i][15] = 0; } };  // right is open
		if (flags & 0b0100) { for (int i = 1; i < 14; i++) { area[15][i] = 0; } }; // bottom is open
		if (flags & 0b1000) { for (int i = 1; i < 14; i++) { area[i][0] = 0; } }; // left is open
	}

	this->flags = flags;
}

void Area::display() {
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 16; k++) {
			std::cout << area[i][k];
		}
		std::cout << std::endl;
	}
}

