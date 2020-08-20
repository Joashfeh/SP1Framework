#pragma once
#include "Map.h"
#include "Entity.h"
#include "colours.h"

class Player :
    public Entity {
public:
    
    COLOURS renderColour;

    Player();
    void Attack(Entity* ptrEntity);
    void Defend();

    void spawn(Map* map);
};

