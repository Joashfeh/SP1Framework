#pragma once
#include "Item.h"
class Armor :
    public Item
{
public:
    int dmgreduc;
    int armorhealth;
    int cost;

    Armor(std::string name);
    ~Armor();

};

