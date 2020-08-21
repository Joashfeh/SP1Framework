#include "Player.h"


Player::Player() {
	HP = 100;
}

void Player::Attack(Entity* ptrEntity) {
}

void Player::Defend() {
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
