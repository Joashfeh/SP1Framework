#pragma once
#include "Map.h"
#include "Entity.h"
#include "colours.h"
#include "Weapon.h"
#include "Armor.h"

class Player :
    public Entity {
public:
    Weapon mainWeapon;
    Armor mainArmor;
    
    int maxHealth = 100 + mainArmor.armorHealth;
    int maxArmor = 30 + mainArmor.defence;  

    bool isDefend;

    Player();
    void Attack(Entity* ptrEntity, Console& g_Console);
    void Defend();

    void spawn(Map* map);
    void reset();
};

