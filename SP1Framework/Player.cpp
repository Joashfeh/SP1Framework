#include "Player.h"

Player::Player(Map &Map)
{
	for (int row = 0; row < 96; row++) {
		for (int col = 0; col < 192; col++) {
			if (Map.toDisplay[row][col] == 2) {
				this->Pos.row = row;
				this->Pos.col = col;
			}
		}
	}
	HP = 100;
}

void Player::Attack(Entity* ptrEntity)
{
	
}

void Player::Defend()
{
}
