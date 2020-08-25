#include "updateGameOver.h"

void updateGameOver(SKeyEvent* g_skKeyEvent, EGAMESTATES& g_eGameState, Player& plr) {
	if (g_skKeyEvent[K_SPACE].keyDown) {
		plr.reset();
		init();
		g_eGameState = S_GAME;
	}
}
