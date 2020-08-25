#pragma once
#include "renderEnemyDamage.h"

int g_iEnemyCurrentFrame{ 0 };
static int g_iEnemyFrameNumber{ 0 };
int g_iEnemyMaxFrames{ 0 };

//Trigger
bool g_bIsRenderDamageEnemy{ false };

void renderEnemyDamage(Console& console, Enemy& enemy, int playerDMG) {

	if (g_bIsRenderDamageEnemy == false)
		return;

	switch (g_iEnemyFrameNumber) {
	case 0:
		enemy.renderColour = COLOURS::WHITE;
		break;
	case 5:
		enemy.renderColour = COLOURS::RED;
		break;
	case 10:
		enemy.renderColour = COLOURS::RED;
		break;
	default:
		break;
	}

	console.writeToBuffer(60, 5, std::to_string(playerDMG));

	// End of render
	if (g_iEnemyCurrentFrame == g_iEnemyMaxFrames)
	{
		//Reset values
		g_iEnemyCurrentFrame = 0;
		g_iEnemyFrameNumber = 0;
		g_bIsRenderDamageEnemy = false;

	}

	g_iEnemyCurrentFrame++;
	++g_iEnemyFrameNumber %= 10;
}

void triggerRenderEnemyDamage() {

	if (g_bIsRenderDamageEnemy)
		return;

	g_bIsRenderDamageEnemy = true;
	g_iEnemyMaxFrames = 20;
}