#include "Player.h"
#include "renderEnemyDamage.h"
#include "Framework/console.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Player::Player() {
	HP = 100;
	Damage = 10;
	Defense = 30;
	skulls = 0;

	isDefend = false;
	gold = 0;
}

void Player::Attack(Entity* ptrEntity, Console& g_Console, int turn) {

	int damage = this->Damage + mainWeapon.dmg;

	srand(time(0));

	int chance;

	if (ptrEntity->Defense == 0)
		ptrEntity->HP -= damage;

	if (ptrEntity->Defense != 0) {
		switch (ptrEntity->special_defence)
		{
		case 'F': // Full block
			chance = floor(rand() % ptrEntity->total_stats_points);
			if (chance <= ptrEntity->Defense)
			{
				ptrEntity->HP -= 0;
				ptrEntity->Defense -= damage * 0.5;
			}
			else
			{
				// Block did not occur
				ptrEntity->HP -= damage * 0.5;
				ptrEntity->Defense -= damage * 0.5;
			}
			break;
		case 'D': // Deflective block
			if (ptrEntity->Defense >= 10 && ptrEntity->Defense < 100) // 25% deflect
			{
				ptrEntity->HP -= damage * 0.5;
				ptrEntity->Defense -= damage * 0.5;

				HP -= floor(damage * (1 / 4));
			}

			else if (ptrEntity->Defense >= 100 && ptrEntity->Defense < 1000) // 50% deflect | Update: Nerfed to 33% for balance
			{
				ptrEntity->HP -= damage * 0.5;
				ptrEntity->Defense -= damage * 0.5;

				HP -= floor(damage * (1 / 3));
			}

			else
			{
				// 'D' block not applied when out of range.
				ptrEntity->HP -= damage * 0.5;
				ptrEntity->Defense -= damage * 0.5;
			}
		default:
			ptrEntity->HP -= damage * 0.5;
			ptrEntity->Defense -= damage * 0.5;
			break;
		}
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

