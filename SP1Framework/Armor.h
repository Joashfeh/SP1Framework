#pragma once
#include "Item.h"
class Armor :
    public Item
{
public:

    std::string name;
    int dmgReduc;
    int armorHealth;
    int cost;

    Armor(std::string name);
    ~Armor();

    void loadArmor(int id);

};

