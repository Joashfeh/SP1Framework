#pragma once
#include "keyEvents.h"
#include "loadCharacter.h"
#include "renderCharacterDamage.h"
#include "Framework/console.h"
#include "battleInterface.h"
#include "Player.h"

void renderBattle(double& g_dElapsedTime, Console& g_Console, Player& plr);
void battleKBHandler(const KEY_EVENT_RECORD& keyboardEvent, SKeyEvent* g_skKeyEvent);