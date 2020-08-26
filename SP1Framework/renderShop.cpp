#include "renderShop.h"
#include <fstream>
#include "Player.h"

void renderItemBought(Console& g_Console, Player& plr, SMouseEvent& g_mouseEvent)
{
    if (ConfirmationBox::itemBought[0] == true)//if weapon is bought
    {
        g_Console.writeToBuffer(56, 14, "You got");
        g_Console.writeToBuffer(56, 15, plr.mainWeapon.name);
        g_Console.writeToBuffer(61, 27, "OK");
        displayBoxes(g_Console, 52, 16, 20, 10);
        std::string WeaponSprite = "Sprite_data/Weapon_sprite/Weapon0";
        WeaponSprite += std::to_string(plr.mainWeapon.id);
        WeaponSprite += ".txt";
        std::ifstream WeaponBought(WeaponSprite, std::ios::in);
        if (!WeaponBought)
            return;

        COORD weapon;
        weapon.X = 54;
        weapon.Y = 17;

        COLOURS outputColour;

        for (int i = 0; i < 8; i++) {
            std::string file;
            std::getline(WeaponBought, file);

            for (int col = 0; col < 8; col++) {
                switch (file[col])
                {
                case '0': outputColour = COLOURS::BLACK;
                    break;
                case '1': outputColour = COLOURS::WHITE;
                    break;
                }
                g_Console.writeToBuffer(weapon, " ", outputColour);
                weapon.X++;
                g_Console.writeToBuffer(weapon, " ", outputColour);
                weapon.X++;
            }
            weapon.X = 54;
            weapon.Y++;
        }

        WeaponBought.close();

    }

    
    if (ConfirmationBox::itemBought[1] == true)//if armor is bought
    {
        g_Console.writeToBuffer(56, 14, "You got");
        g_Console.writeToBuffer(56, 15, plr.mainArmor.name);
        g_Console.writeToBuffer(61, 27, "OK");
        displayBoxes(g_Console, 52, 16, 20, 10);
        std::string ArmorSprite = "Sprite_data/Armor_sprite/Armor0";
        ArmorSprite += std::to_string(plr.mainArmor.id);
        ArmorSprite += ".txt";
        std::ifstream ArmorBought(ArmorSprite, std::ios::in);
        if (!ArmorBought)
            return;

        COORD armor;
        armor.X = 54;
        armor.Y = 17;

        COLOURS outputColour;

        for (int i = 0; i < 8; i++) {
            std::string file;
            std::getline(ArmorBought, file);

            for (int col = 0; col < 8; col++) {
                switch (file[col])
                {
                case '0': outputColour = COLOURS::BLACK;
                    break;
                case '1': outputColour = COLOURS::WHITE;
                    break;
                }
                g_Console.writeToBuffer(armor, " ", outputColour);
                armor.X++;
                g_Console.writeToBuffer(armor, " ", outputColour);
                armor.X++;
            }
            armor.X = 54;
            armor.Y++;
        }

        ArmorBought.close();
    }
    
    for (int col = 61; col < 63; col++)
        if ((g_mouseEvent.mousePosition.X == col) && (g_mouseEvent.mousePosition.Y == 27))
            if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                ConfirmationBox::itemBought[1] = false;
                ConfirmationBox::itemBought[0] = false;
            }
}

void renderShop(Console& g_Console, Player& plr, SMouseEvent& g_mouseEvent)
{
    renderShopinterface(g_Console, plr);
    renderConfirmation(g_Console);
    renderItemBought(g_Console, plr, g_mouseEvent);
}
