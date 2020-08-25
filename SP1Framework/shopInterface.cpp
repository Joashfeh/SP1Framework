#include "shopInterface.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <sstream>

bool ConfirmationBox::appear = false;
bool ConfirmationBox::no = false;
bool ConfirmationBox::yes = false;
bool ConfirmationBox::itemToBuy[8] = { false, false, false, false, false, false, false, false };
bool ConfirmationBox::rejection = false;

void renderShopinterface(Console& g_Console, Player& plr)
{
    mainDisplay(g_Console);//white border
    COORD shop;
    shop.X = 29;//setting coordinates for "The Shop!" to appear
    shop.Y = 1;

    COORD armour;
    armour.X = 70;//setting coordinates for "Armour" to appear
    armour.Y = 8;

    COORD weapon;
    weapon.X = 6;//setting coordinates for "Weapon" to appear
    weapon.Y = 8;

    std::string File = "Shop_data/Shop.txt";//opening shop file
    std::ifstream titleShop(File, std::ios::in);
    if (!titleShop)
        return;

    std::string FileArmour = "Shop_data/Armour.txt";//opening armour file
    std::ifstream titleArmour(FileArmour, std::ios::in);
    if (!titleArmour)
        return;

    std::string FileWeapon = "Shop_data/Weapon.txt";//opening weapon file
    std::ifstream titleWeapon(FileWeapon, std::ios::in);
    if (!titleWeapon)
        return;

    // Loading all 3 files
    for (int row = 0; row < 6; row++) {

        std::string a;
        std::getline(titleShop, a);

        for (int col = 0; col < 62; col++) {
            g_Console.writeToBuffer(shop, a[col]);
            shop.X++;
        }
        shop.X = 29;
        shop.Y++;

        std::string b;
        std::getline(titleArmour, b);

        for (int col = 0; col < 46; col++) {
            g_Console.writeToBuffer(armour, b[col]);
            armour.X++;
        }
        armour.X = 70;
        armour.Y++;

        std::string c;
        std::getline(titleWeapon, c);

        for (int col = 0; col < 48; col++) {
            g_Console.writeToBuffer(weapon, c[col]);
            weapon.X++;
        }
        weapon.X = 6;
        weapon.Y++;
    }

    titleShop.close();//closing shop file

    titleArmour.close();//closing armour file

    titleWeapon.close();//closing weapon file

    displayBoxes(g_Console, 6, 14, 48, 23);//display for weapon
    displayBoxes(g_Console, 70, 14, 45, 23);//display for armour

    //initialising all the weapons
    Weapon Weapon1(1);
    Weapon Weapon2(2);
    Weapon Weapon3(3);
    Weapon Weapon4(4);
    Weapon Weapon5(5);

    //initialising all armour
    Armor Armor1(1);
    Armor Armor2(2);
    Armor Armor3(3);

    //adding all weapon to shop
    insertWeapon(g_Console, 8, 15, Weapon1);
    insertWeapon(g_Console, 8, 19, Weapon2);
    insertWeapon(g_Console, 8, 23, Weapon3);
    insertWeapon(g_Console, 8, 27, Weapon4);
    insertWeapon(g_Console, 8, 31, Weapon5);

    //adding all armour to shop
    insertArmour(g_Console, 72, 15, Armor1);
    insertArmour(g_Console, 72, 23, Armor2);
    insertArmour(g_Console, 72, 31, Armor3);

    //display the player's gold
    std::string gold_output = std::to_string(plr.gold);
    displayBoxes(g_Console, 6, 2, 20, 4);
    g_Console.writeToBuffer(7, 3, "Gold:");
    g_Console.writeToBuffer(7, 4, gold_output);

}

void insertWeapon(Console& g_Console, int x, int y, Weapon weapon)
{
    std::stringstream ss;
    ss.str("");
    ss << weapon.cost;//get cost of weapon
    g_Console.writeToBuffer(x, y, weapon.name);//put name of weapon
    g_Console.writeToBuffer(34, y, ss.str());//put cost beside it
    g_Console.writeToBuffer(39, y, "Gold");//put "Gold" as currency

    //getting damage and displaying it
    ss.str("");
    ss << weapon.dmg;
    g_Console.writeToBuffer(x, y + 1, ss.str());
    g_Console.writeToBuffer(x + 4, y + 1, "Damage");

    //getting crit damage and displaying it
    ss.str("");
    ss << weapon.crit;
    g_Console.writeToBuffer(x, y + 2, ss.str());
    g_Console.writeToBuffer(x + 4, y + 2, "Crit damage");
    g_Console.writeToBuffer(47, y, "BUY");//indicating where to click if they want to buy it
}

void insertArmour(Console& g_Console, int x, int y, Armor armor)
{
    std::stringstream ss;
    ss.str("");
    ss << armor.cost;
    g_Console.writeToBuffer(x, y, armor.name);
    g_Console.writeToBuffer(95, y, ss.str());
    g_Console.writeToBuffer(100, y, "Gold");

    //getting armour health and displaying it
    ss.str("");
    ss << armor.armorHealth;
    g_Console.writeToBuffer(x, y + 1, ss.str());
    g_Console.writeToBuffer(x + 5, y + 1, "Armor health");

    //getting damage reduction and displaying it
    ss.str("");
    ss << armor.defence;
    g_Console.writeToBuffer(x, y + 2, ss.str());
    g_Console.writeToBuffer(x + 5, y + 2, "Defence");

    g_Console.writeToBuffer(108, y, "BUY");
}

void confirmationBox(Console& g_Console)
{
    displayBoxes(g_Console, 52, 16, 20, 8);
    g_Console.writeToBuffer(55, 17, "Purchase");

    for (int i = 0; i < 8; i++)
    {
        if (ConfirmationBox::itemToBuy[i] == true)
        {
            g_Console.writeToBuffer(55, 18, checkItem(i));
        }
    }

    g_Console.writeToBuffer(55, 19, "Are you sure?");
    g_Console.writeToBuffer(57, 21, "Yes");
    g_Console.writeToBuffer(64, 21, "No");
}


void rejectionBox(Console& g_Console)
{
    displayBoxes(g_Console, 52, 16, 20, 8);
    g_Console.writeToBuffer(53, 17, "Insufficient money");
    g_Console.writeToBuffer(53, 18, "Come back when you");
    g_Console.writeToBuffer(53, 19, "have enough money.");
    g_Console.writeToBuffer(61, 21, "OK");
}

void renderConfirmation(Console& g_Console)
{
    if (ConfirmationBox::appear == true)
        confirmationBox(g_Console);
    if (ConfirmationBox::rejection == true)
        rejectionBox(g_Console);

}

std::string checkItem(int id)
{
    std::string item = "";
    switch (id)
    {
    case 0: item += "Stick";
        break;
    case 1: item += "Dagger";
        break;
    case 2: item += "Battle Axe";
        break;
    case 3: item += "Death Scythe";
        break;
    case 4: item += "Excalibur";
        break;
    case 5: item += "Light Armor";
        break;
    case 6: item += "Heavy Armor";
        break;
    case 7: item += "Juggernaught";
        break;
    }

    return item;
}

