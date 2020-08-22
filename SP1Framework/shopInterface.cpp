#include "shopInterface.h"
#include <fstream>
#include <string>
#include <sstream>

bool ConfirmationBox::appear = false;
bool ConfirmationBox::no = false;
bool ConfirmationBox::yes = false;

void renderShopinterface(Console& g_Console)
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
    displayBoxes(g_Console, 6, 2, 20, 4);
    g_Console.writeToBuffer(7, 3, "Gold:");
    g_Console.writeToBuffer(7, 4, "get players gold");

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
    g_Console.writeToBuffer(x + 5, y + 1, "Armour health");

    //getting damage reduction and displaying it
    ss.str("");
    ss << armor.dmgReduc << "%";
    g_Console.writeToBuffer(x, y + 2, ss.str());
    g_Console.writeToBuffer(x + 5, y + 2, "Armour Reduction");

    g_Console.writeToBuffer(108, y, "BUY");
}

void confirmationBox(Console& g_Console)
{
    displayBoxes(g_Console, 52, 16, 20, 7);
    g_Console.writeToBuffer(55, 19, "Are you sure?");
    g_Console.writeToBuffer(57, 21, "Yes");
    g_Console.writeToBuffer(64, 21, "No");
}

void renderConfirmation(Console& g_Console)
{
    if (ConfirmationBox::appear == true)
        confirmationBox(g_Console);
    if (ConfirmationBox::no == true)
    {
        ConfirmationBox::appear = false;
        ConfirmationBox::no = false;
    }

}

void checkBuyButton(SMouseEvent& g_mouseEvent, int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        if ((g_mouseEvent.mousePosition.X == x + i) && (g_mouseEvent.mousePosition.Y == y))
        {
            if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                ConfirmationBox::appear = true;
            }
        }
    }
}
