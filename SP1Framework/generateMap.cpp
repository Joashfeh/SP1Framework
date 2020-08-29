#include "generateMap.h"

void spawnEnemies(Map& map, Enemy* arr[]) {

    for (int i = 0; i < 3; i++) {
        arr[i] = nullptr;
    }


    for (int i = 0; i < 3; i++) {
        if (arr[i] == nullptr) {
            arr[i] = new Enemy;
            arr[i]->loadEnemy(map.floor, i);                             
        }
    }

    switch (map.floor) {
    case 1:
        arr[0]->setPos(69, 110);
        arr[1]->setPos(55, 110);
        arr[2]->setPos(40, 110);
        break;
    
    case 4:
        arr[0]->setPos(24, 47);
        arr[1]->setPos(24, 80);
        arr[2]->setPos(24, 113);

        arr[2]->enemyType = 2;
        break;

    case 8:
        arr[0]->setPos(24, 47);
        arr[1]->setPos(24, 80);
        arr[2]->setPos(24, 113);

        arr[2]->enemyType = 2;
        break;

    case 12:
        arr[0]->setPos(24, 47);
        arr[1]->setPos(24, 80);
        arr[2]->setPos(24, 113);

        arr[2]->enemyType = 3;
        break;

    default:
        
        for (int i = 0; i < 3; i++) {

            int x = rand() % 192;
            int y = rand() % 96;

            if (map.display[y][x] != '9') {
                i--;
            }
            else if (map.display[y][x] == '9') {
                arr[i]->Pos.row = y;
                arr[i]->Pos.col = x;
                map.display[y][x] = '3';
            }
        }
        break;
    
    }
    

}

void generateMap(Map& map, Player& plr, Enemy* enemies[], goldCrate* crate, int floor) {
    int floorType;
    
    switch (floor) {
    case 1: floorType = 0;
        break;
    case 4: floorType = 2;
        break;
    case 8: floorType = 2;
        break;
    case 12: floorType = 2;
        break;
    default: floorType = 1;
        break;
    }

	map.generateDungeon(floor, floorType);
    spawnEnemies(map, enemies);

    for (int i = 0; i < 3; i++) {
        map.display[enemies[i]->Pos.row][enemies[i]->Pos.col] = '3';
    }

	plr.spawn(&map);
}
