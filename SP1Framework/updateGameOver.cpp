#include "updateGameOver.h"
#include "Enemy.h"

void updateGameOver(SKeyEvent* g_skKeyEvent, EGAMESTATES& g_eGameState, Player& plr) {
	if (g_skKeyEvent[K_SPACE].keyDown) {
		plr.reset();
		Enemy::enemyCount = 0;
		init();
		g_eGameState = S_GAME;
	}
}
