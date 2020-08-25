#include "updateInventory.h"

void updateInventory(Console& g_Console, SKeyEvent* g_skKeyEvent, EGAMESTATES& g_eGameState)
{
	if (g_skKeyEvent[K_INVENTORY].keyDown)
		g_eGameState = S_GAME;
}
