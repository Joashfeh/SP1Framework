#pragma once
#include <string>
#include "Item.h"
class Weapon :
    public Item
{
public:
    
    std::string name;

    int dmg;
    int cost;
    int crit;
    int skull_cost;

    Weapon();
    Weapon(int id);
    ~Weapon();

    void loadWeapon(int id);

};

