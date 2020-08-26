#pragma once
#include "Framework/console.h"
#include "Map.h"
#include "game.h"

void renderLevelTransition(Console& g_Console, EGAMESTATES& g_eGameState, Map& map);
void triggerLevelTransition();
