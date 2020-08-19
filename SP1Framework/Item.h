#pragma once
#include <string>
class Item
{

public:

    int id;
    int gold;

    Item();
    Item(std::string itemName);
    ~Item();

};
