#include "updateGameOver.h"

void updateGameOver(SKeyEvent* g_skKeyEvent, EGAMESTATES& g_eGameState, Player& plr, Enemy* arr[]) {
	if (g_skKeyEvent[K_SPACE].keyDown) {
		plr.reset();

		for (int i = 0; i < 3; i++) {
			if (arr[i] == nullptr) {
				delete arr[i];
				arr[i] = nullptr;
			}
		}

		Enemy::enemyCount = 0;
		init();
		g_eGameState = S_GAME;
	}
}
