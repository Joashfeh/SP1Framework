#include "Player.h"
#include "renderEnemyDamage.h"
#include "Framework/console.h"

Player::Player() {
	HP = 100;
	Damage = 10;
	Defense = 30;


	isDefend = false;
	gold = 0;
}

void Player::Attack(Entity* ptrEntity, Console& g_Console, int turn) {

	int damage = this->Damage + mainWeapon.dmg;

	if (ptrEntity->Defense == 0)
		ptrEntity->HP -= damage;

	if (ptrEntity->Defense != 0) {
		ptrEntity->HP -= floor(damage / ptrEntity->Defense);
		ptrEntity->Defense -= floor(damage / ptrEntity->Defense);
	}

	if (ptrEntity->Defense < 0)
		ptrEntity->Defense = 0;

	if (ptrEntity->HP < 0)
		ptrEntity->HP = 0;

	triggerRenderEnemyDamage();
}

void Player::Defend() {
	isDefend = true;
}

void Player::equipArmor()
{
	maxHealth = 100 + mainArmor.armorHealth;
	maxArmor = 30 + mainArmor.defence;
}

void Player::spawn(Map* map) {
	for (int row = 0; row < 96; row++) {
		for (int col = 0; col < 96; col++) {
			if (map->fullMap[row][col] == '2') {
				this->Pos.row = row;
				this->Pos.col = col * 2;
			}
		}
	}
}

void Player::reset() {
	mainWeapon.dmg = 0;
	mainWeapon.crit = 0;
	mainWeapon.cost = 0;
	mainWeapon.id = 0;

	mainArmor.armorHealth = 0;
	mainArmor.defence = 0;
	mainArmor.cost = 0;
	mainArmor.id = 0;

	HP = 100;
	Damage = 10;
	Defense = 30;
	gold = 0;
}

