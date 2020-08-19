#include "generateMap.h"

Enemies* arr[3] = { nullptr, nullptr, nullptr };

void spawnEnemies(Map& map) {
    for (int i = 0; i < 3; i++) {
        if (arr[i] != nullptr) {
            arr[i] = new Enemies;
            int x = rand() % 192;
            int y = rand() % 96;

            arr[i]->pos.row = y;
            arr[i]->pos.col = x;

            if (map.display[arr[i]->pos.row][arr[i]->pos.col] != '9') {
                delete arr[i];
                arr[i] = nullptr;
                i--;
            }
            else {
                map.display[arr[i]->pos.row][arr[i]->pos.col] = '3';
            }
        }
    }
}

void generateMap(Map& map, Player& plr) {
	map.generateDungeon();
    spawnEnemies(map);
	plr.spawn(&map);
}
