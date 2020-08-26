#pragma once
#include "Player.h"
#include "Interface.h"
#include "colours.h"
#include "renderCharacterSprite.h"


void displayStats(Console& g_Console, Player& plr);
void renderWeaponSprite(Console& g_Console, Player& plr);
void renderArmorSprite(Console& g_Console, Player& plr);
void renderInventory(Console& g_Console, Player& plr,double dt);
