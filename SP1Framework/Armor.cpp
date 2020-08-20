#include "Armor.h"
#include <string>
#include <fstream>

Armor::Armor(std::string name)
{

}

Armor::~Armor()
{

}
void Armor::loadArmor(int id) {
	std::string armorDir;
	armorDir = "Weapon_data/weapon_0";

	armorDir += std::to_string(id);
	armorDir += ".txt";

	std::ifstream armorData(armorDir, std::ios::in);
	if (!armorData)
		return;

	for (int i = 0; i < 4; i++) {
		std::string a;
		std::getline(armorData, a);

		switch (i) {
		case 0:
			name = a;
			break;
		case 1:
			dmgReduc = stoi(a);
			break;
		case 2:
			armorHealth = stoi(a);
			break;
		case 3:
			cost = stoi(a);
			break;
		}
	}

	armorData.close();

}