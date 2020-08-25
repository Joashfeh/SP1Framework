#include "updateBattle.h"
#include "keyEvents.h"

bool activeAction{ false };
double battleFrame = 0;

bool checkMousePos(SMouseEvent& g_mouseEvent, int x, int y) {
	if (g_mouseEvent.mousePosition.X == x && g_mouseEvent.mousePosition.Y == y)
		return true;
	
	else 
		return false;
}

void updateBattle(Console& g_Console, SMouseEvent& g_mouseEvent, EGAMESTATES& g_eGameState, Player& plr, Enemy& enemy, int& turn, double dt) {

	if (activeAction) {
		battleFrame += dt;

		if (battleFrame > 1){
			activeAction = false;
			battleFrame = 0;
		}
			
		return;
	}

	if (enemy.HP == 0) {
		turn = 1;

		g_eGameState = S_GAME;
	}

	if (plr.HP == 0) {
		g_eGameState = S_GAMEOVER;
	}

	switch (turn % 2) {
	case 0: // Enemy Turn
		enemy.Attack(&plr, g_Console);
		turn++;
		triggerBattleAction();
		break;
	case 1: // Player Turn
		for (int row = 30; row < 38; row++) {
			for (int col = 4; col < 50; col++) {
				if (checkMousePos(g_mouseEvent, col, row)) {
					if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
						plr.Attack(&enemy, g_Console);
						turn++;

						triggerBattleAction();
						break;
					}
				}
			}
		}

		for (int row = 30; row < 38; row++) {
			for (int col = 67; col < 115; col++) {
				if (checkMousePos(g_mouseEvent, col, row)) {
					if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
						plr.Defend();
						turn++;

						triggerBattleAction();
						break;
					}
				}
			}
		}
		break;
	}

}

void triggerBattleAction() {

	if (activeAction)
		return;

	activeAction = true;
}
