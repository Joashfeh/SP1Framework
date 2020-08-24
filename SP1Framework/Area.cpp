#include "Area.h"
#include <string>
#include <fstream>

Area::Area() {
	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 16; k++) {
			area[i][k] = '0';
		}
	}
}

Area::Area(unsigned short flags, int doorSize, int roomType) {

	int terrainNo = rand() % 11 + 1;

	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 16; k++) {
			area[i][k] = '0';
		}
	}

	for (int i = 0; i < 16; i++) {
		for (int k = 0; k < 16; k++) {
			if (i == 0 || i == 15) area[i][k] = '1';
			if (k == 0 || k == 15) area[i][k] = '1';
		}
	}

	if (roomType == 0) { // Spawn Room
		for (int i = 1; i < 15; i++) {
			for (int k = 1; k < 15; k++) {
				area[i][k] = '0';
			}
		}
		area[8][7] = '2';
	}

	if (roomType == 1) { // Normal Room
		loadMap(terrainNo);
	}

	if (roomType == 2) { // Exit Room

		area[8][7] = 'L';

	}

	if (roomType == 3) { // Empty Rooms
		for (int i = 1; i < 15; i++) {
			for (int k = 1; k < 15; k++) {
				area[i][k] = '0';
			}
		}
	}

	if (doorSize == 1) {
		if (flags & 0b0001) { area[0][6] = '0'; area[0][7] = '0'; area[0][8] = '0'; area[0][9] = '0'; }; // top is open
		if (flags & 0b0010) { area[6][15] = '0'; area[7][15] = '0'; area[8][15] = '0'; area[9][15] = '0'; }; // right is open
		if (flags & 0b0100) { area[15][6] = '0'; area[15][7] = '0'; area[15][8] = '0'; area[15][9] = '0'; }; // bottom is open
		if (flags & 0b1000) { area[6][0] = '0'; area[7][0] = '0'; area[8][0] = '0'; area[9][0] = '0'; }; // left is open
	}

	if (doorSize == 2) {
		if (flags & 0b0001) { for (int i = 1; i < 15; i++) { area[0][i] = '0'; } }; // top is open
		if (flags & 0b0010) { for (int i = 1; i < 15; i++) { area[i][15] = '0'; } };  // right is open
		if (flags & 0b0100) { for (int i = 1; i < 15; i++) { area[15][i] = '0'; } }; // bottom is open
		if (flags & 0b1000) { for (int i = 1; i < 15; i++) { area[i][0] = '0'; } }; // left is open

		area[7][7] = '9';

	}

	this->flags = flags;
}

void Area::loadMap(int terrainNo) {
	std::string snewMapFileName;
	snewMapFileName = "Terrain_data/Terrain";

	if (terrainNo < 10)
		snewMapFileName += "0";

	snewMapFileName += std::to_string(terrainNo);
	snewMapFileName += ".txt";

	// Open file
	std::ifstream inmapData(snewMapFileName, std::ios::in);
	if (!inmapData)
		return;

	// Load
	for (int row = 0; row < 16; row++) {

		std::string a;
		std::getline(inmapData, a);

		for (int col = 0; col < 16; col++) {
			area[row][col] = a[col];
		}
	}

	// Close file
	inmapData.close();
}

