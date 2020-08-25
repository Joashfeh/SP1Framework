#include "Inventory.h"
#include <fstream>
#include <sstream>

void displaygold()
{
}

void renderWeaponSprite(Console& g_Console, Player& plr)
{
	std::string WeaponSpriteFile = "Sprite_data/Weapon_sprite/Weapon0";
	WeaponSpriteFile += std::to_string(plr.mainWeapon.id);
	WeaponSpriteFile += ".txt";

	std::ifstream WeaponSprite(WeaponSpriteFile, std::ios::in);
	if (!WeaponSprite)
		return;

	COORD weapon;
	weapon.X = 7;
	weapon.Y = 4;

	COLOURS outputColour = COLOURS::WHITE;

	for (int i = 0; i < 8; i++)
	{
		std::string a;
		std::getline(WeaponSprite, a);

		for (int col = 0; col < 8; col++) {
			switch (a[col])
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
		weapon.X = 7;
		weapon.Y++;
	}


	WeaponSprite.close();
}

void renderInventory(Console& g_Console, Player& plr)
{
	mainDisplay(g_Console);
	displayBoxes(g_Console, 5, 3, 20, 10);
	renderWeaponSprite(g_Console, plr);
}
