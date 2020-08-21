#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Framework/console.h"
#include "keyEvents.h"

bool checkMousePos(SMouseEvent& g_mouseEvent, int x, int y);

void updateBattle(Console& g_Console, SMouseEvent& g_mouseEvent, Player& plr, Enemy& enemy, int turn);
void triggerBattleAction();