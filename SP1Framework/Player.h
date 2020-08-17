#pragma once
#include "Map.h"
#include "Entity.h"
class Player :
    public Entity
{
public:
    
    Player(Map &Map);
    void Attack(Entity* ptrEntity);
    void Defend();
};

