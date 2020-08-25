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

void Player::Attack(Entity* ptrEntity, Console& g_Console) {

	int damage = this->Damage + mainWeapon.dmg;

	if (ptrEntity->Defense == 0)
<<<<<<< HEAD
		ptrEntity->HP -= this->Damage + mainWeapon.dmg;

	if (ptrEntity->Defense != 0) {
		ptrEntity->HP -= (this->Damage + mainWeapon.dmg) * 0.5;
		ptrEntity->Defense -= (this->Damage + mainWeapon.dmg) * 0.5;
=======
		ptrEntity->HP -= damage;

	if (ptrEntity->Defense != 0) {
		ptrEntity->HP -= damage * 0.5;
		ptrEntity->Defense -= damage * 0.5;
>>>>>>> 8148ffd43b3107c244028fadf34cbd693db8605a
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

