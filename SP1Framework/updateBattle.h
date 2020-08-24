#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Framework/console.h"
#include "keyEvents.h"
#include "battleInterface.h"
#include "game.h"

bool checkMousePos(SMouseEvent& g_mouseEvent, int x, int y);

void updateBattle(Console& g_Console, SMouseEvent& g_mouseEvent, EGAMESTATES& g_eGameState, Player& plr, Enemy& enemy, int& turn, double dt);
void triggerBattleAction();