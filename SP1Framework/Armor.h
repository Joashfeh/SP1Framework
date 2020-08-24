#pragma once
#include "Item.h"
class Armor :
    public Item
{
public:

    std::string name;
    int defence;
    int armorHealth;
    int cost;

    Armor();
    Armor(int id);
    Armor(std::string name);
    ~Armor();

    void loadArmor(int id);

};

