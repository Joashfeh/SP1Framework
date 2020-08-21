#include "updateMainMenu.h"

void updateMainMenu(SKeyEvent* g_skKeyEvent, EGAMESTATES& g_eGameState) {
	if (g_skKeyEvent[K_SPACE].keyReleased)
		g_eGameState = S_GAME;
}
