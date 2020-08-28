#include "Inventory.h"
#include <fstream>
#include <sstream>



void displayStats(Console& g_Console, Player& plr)
{
	std::stringstream stats;
	stats.str("");
	stats << "Gold: " << plr.gold;
	g_Console.writeToBuffer(7, 15, stats.str());
	stats.str("");
	stats << "Health: " << plr.HP;
	g_Console.writeToBuffer(7, 17, stats.str());
	stats.str("");
	stats << "Defence: " << plr.Defense;
	g_Console.writeToBuffer(7, 19, stats.str());
	stats.str("");
	stats << "Damage: " << plr.Damage << " + " << plr.mainWeapon.dmg;
	stats.str("");
	stats << "Skulls: " << plr.skulls;
	g_Console.writeToBuffer(7, 21, stats.str());
}

void renderWeaponSprite(Console& g_Console, Player& plr)
{

	g_Console.writeToBuffer(90, 2, "Weapon");
	if (plr.mainWeapon.id == 0)
		g_Console.writeToBuffer(91, 3, "None");
	else
		g_Console.writeToBuffer(93 - plr.mainWeapon.name.length() / 2, 3, plr.mainWeapon.name);

	std::string WeaponSpriteFile = "Sprite_data/Weapon_sprite/Weapon0";
	WeaponSpriteFile += std::to_string(plr.mainWeapon.id);
	WeaponSpriteFile += ".txt";

	std::ifstream WeaponSprite(WeaponSpriteFile, std::ios::in);
	if (!WeaponSprite)
		return;

	COORD weapon;
	weapon.X = 77;
	weapon.Y = 6;

	COLOURS outputColour = COLOURS::WHITE;

	for (int i = 0; i < 8; i++)
	{

		std::string a;
		std::getline(WeaponSprite, a);


		for (int i = 0; i < 2; i++) {
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
				g_Console.writeToBuffer(weapon, " ", outputColour);
				weapon.X++;
				g_Console.writeToBuffer(weapon, " ", outputColour);
				weapon.X++;
			}
			weapon.X = 77;
			weapon.Y++;
		}
	}


	WeaponSprite.close();
}

void renderArmorSprite(Console& g_Console, Player& plr)
{
	g_Console.writeToBuffer(46, 2, "Armour");
	if (plr.mainArmor.id == 0)
		g_Console.writeToBuffer(47, 3, "None");
	else
		g_Console.writeToBuffer(49 - plr.mainArmor.name.length() / 2, 3, plr.mainArmor.name);

	std::string ArmorSpriteFile = "Sprite_data/Armor_sprite/Armor0";
	ArmorSpriteFile += std::to_string(plr.mainArmor.id);
	ArmorSpriteFile += ".txt";

	std::ifstream ArmorSprite(ArmorSpriteFile, std::ios::in);
	if (!ArmorSprite)
		return;

	COORD armor;
	armor.X = 33;
	armor.Y = 6;

	COLOURS outputColour = COLOURS::WHITE;

	for (int i = 0; i < 8; i++)
	{
		std::string a;
		std::getline(ArmorSprite, a);

		for (int i = 0; i < 2; i++) {

			for (int col = 0; col < 8; col++) {
				switch (a[col])
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
				g_Console.writeToBuffer(armor, " ", outputColour);
				armor.X++;
				g_Console.writeToBuffer(armor, " ", outputColour);
				armor.X++;
			}
			armor.X = 33;
			armor.Y++;
		}
	}


	ArmorSprite.close();
}

void renderInventory(Console& g_Console, Player& plr, double dt)
{
	mainDisplay(g_Console);
	displayBoxes(g_Console, 73, 4, 40, 20);
	displayBoxes(g_Console, 29, 4, 40, 20);
	renderWeaponSprite(g_Console, plr);
	renderArmorSprite(g_Console, plr);
	renderCharacterSprite(g_Console, 7, 5, plr, dt);
	displayStats(g_Console, plr);
}
