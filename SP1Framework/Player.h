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
    int skulls; // Player gets a skull upon killing a boss | Can be used to buy Scythe, Excilibr and Juggernaut armor.

    bool isDefend;

    Player();
    void Attack(Entity* ptrEntity, Console& g_Console, int turn);
    void Defend();
    void equipArmor();

    void spawn(Map* map);
    void reset();
};

