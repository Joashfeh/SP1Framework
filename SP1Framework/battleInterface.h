#pragma once
#include "Framework/console.h"
#include "Player.h"
#include "Interface.h"
#include "Enemy.h"

void battleInterface(Console& g_Console);
void renderPlayerStats(Console& g_Console, Player& plr);
void renderEnemyStats(Console& g_Console, Enemy& enemy);
