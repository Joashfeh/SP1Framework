#include "Weapon.h"
#include <fstream>
#include <string>

Weapon::Weapon()
{
	dmg = 0;
	crit = 0;
	cost = 0;
	id = 0;
	skull_cost = 0;
}

Weapon::Weapon(int id) {
	loadWeapon(id);
}

Weapon::~Weapon()
{

}

void Weapon::loadWeapon(int id) {
	std::string weaponDir;
	weaponDir = "Weapon_data/weapon_0";

	weaponDir += std::to_string(id);
	weaponDir += ".txt";

	std::ifstream weaponData(weaponDir, std::ios::in);
	if (!weaponData)
		return;

	for (int i = 0; i < 5; i++) { 
		std::string a;
		std::getline(weaponData, a);

		switch (i) {
		case 0:
			name = a;
			break;
		case 1:
			dmg = stoi(a);
			break;
		case 2:
			cost = stoi(a);
			break;
		case 3:
			crit = stoi(a);
			break;
		case 4:
			skull_cost = stoi(a);
			break;
		}	
	}
	this->id = id;
	weaponData.close();

}