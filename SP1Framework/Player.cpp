#include "Player.h"
#include "renderEnemyDamage.h"
#include "Framework/console.h"

Player::Player() {
	HP = 100;
	Damage = 10;
	Defense = 30;
	gold = 0;
}

void Player::Attack(Entity* ptrEntity, Console& g_Console) {

	if (ptrEntity->Defense == 0)
		ptrEntity->HP -= this->Damage;

	if (ptrEntity->Defense != 0) {
		ptrEntity->HP -= this->Damage * 0.5;
		ptrEntity->Defense -= this->Damage * 0.5;
	}

	if (ptrEntity->Defense < 0)
		ptrEntity->Defense = 0;

	if (ptrEntity->HP < 0)
		ptrEntity->HP = 0;

	triggerRenderEnemyDamage();
}

void Player::Defend() {
	Defense += 10;
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

