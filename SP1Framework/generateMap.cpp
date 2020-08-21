#include "generateMap.h"

void spawnEnemies(Map& map, Enemy* arr[]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i] == nullptr) {
            arr[i] = new Enemy;
            arr[i]->loadEnemy(map.floor + 1, i);
            int x = rand() % 192;
            int y = rand() % 96;

            arr[i]->Pos.row = y;
            arr[i]->Pos.col = x;

            if (map.display[arr[i]->Pos.row][arr[i]->Pos.col] != '9') {
                delete arr[i];
                arr[i] = nullptr;
                i--;
            }
            else {
                Enemy::enemyCount++;
                map.display[arr[i]->Pos.row][arr[i]->Pos.col] = '3';
            }
        }
    }
}

void generateMap(Map& map, Player& plr, Enemy* enemies[], int floor) {
	map.generateDungeon(floor, 1);
    spawnEnemies(map, enemies);
	plr.spawn(&map);
}
