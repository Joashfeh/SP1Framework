#pragma once
#include "keyEvents.h"
#include "renderCharacterSprite.h"
#include "renderCharacterDamage.h"
#include "renderEnemyDamage.h"
#include "Framework/console.h"
#include "battleInterface.h"
#include "Player.h"
#include "renderEnemySprite.h"

void renderBattle(double& g_dElapsedTime, Console& g_Console, Player& plr, Enemy& Enemy, int turn_here);