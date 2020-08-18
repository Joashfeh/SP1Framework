#include "generateMap.h"

void generateMap(Map& map, Player& plr) {
	map.generateDungeon();
	plr.spawn(&map);
}
