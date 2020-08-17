#pragma once
#include "Map.h"
#include "Entity.h"
class Player :
    public Entity
{
public:
    
    Player();
    void Attack(Entity* ptrEntity);
    void Defend();

    void spawn(Map* map);
};

