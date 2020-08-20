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

    Weapon::Weapon(int id) {

        int dmg;
        int cost;
        int crit;
    }
    ~Weapon();

    void loadWeapon(int id);

};

