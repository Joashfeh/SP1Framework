#pragma once
#include <string>
#include "Item.h"
class Weapon :
    public Item
{
public:
    int dmg;
    int cost;

    Weapon(std::string name);
    ~Weapon();

};

