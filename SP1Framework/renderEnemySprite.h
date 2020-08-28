#pragma once
#include "Framework/console.h"
#include "Enemy.h"

void renderEnemySprite(Console& console, short x, short y, Enemy& enemy, int turn_input);
void renderEnemySprite(Console& console, COORD c, Enemy& enemy, int current_turn);