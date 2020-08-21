#pragma once
#include "Map.h"
#include "Entity.h"
#include "colours.h"

class Player :
    public Entity {
public:

    Player();
    void Attack(Entity* ptrEntity, Console& g_Console);
    void Defend();

    void spawn(Map* map);
};

