#include "updateBattle.h"
#include "keyEvents.h"

int g_ibattleCurrentFrame{ 0 };
static int g_iBattleFrameNumber{ 0 };
bool activeAction{ false };
int g_iBattleMaxFrames{ 0 };

bool checkMousePos(SMouseEvent& g_mouseEvent, int x, int y) {
	if (g_mouseEvent.mousePosition.X == x && g_mouseEvent.mousePosition.Y == y)
		return true;
	
	else 
		return false;
}

void updateBattle(Console& g_Console, SMouseEvent& g_mouseEvent, Player& plr, Enemy& enemy, int turn) {
	
	if (activeAction)
		return;

	switch (turn) {
	case 0: // Enemy Turn
		turn++;
		break;
	case 1: // Player Turn
		for (int row = 30; row < 38; row++) {
			for (int col = 4; col < 50; col++) {
				if (checkMousePos(g_mouseEvent, col, row)) {
					if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
						plr.Attack(&enemy, g_Console);
					}
				}
			}
		}
		turn++;
		break;
	}

}

void triggerBattleAction() {

	if (activeAction)
		return;

	activeAction = true;
	activeAction = 20;
}
