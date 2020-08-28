#pragma once
#include <iostream>
#include "Framework/console.h"
#include "Player.h"
#include "game.h"
#include "colours.h"
#include "Enemy.h"

void battleTransitionAnimation(Console& g_Console, double dt, EGAMESTATES& g_eGameState, int enemyType);
void triggerBattleAnimation();




