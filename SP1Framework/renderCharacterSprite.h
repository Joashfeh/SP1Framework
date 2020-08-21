#pragma once
#include "Framework/console.h"
#include "Player.h"

void renderCharacterSprite(Console& console, short x, short y, Player& plr, double dt);
void renderCharacterSprite(Console& console, COORD c, Player& plr, double dt);