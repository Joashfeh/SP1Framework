#include "loadMap.h"

void loadMap(Map* map, int floorNumber, int floorType) {
	if (map != nullptr) {
		delete map;
		map = nullptr;
	}

	map = new Map(floorNumber, floorType);
}
