#pragma once
#include "renderCharacterDamage.h"

int g_iPlayerCurrentFrame{ 0 };
static int g_iPlayerFrameNumber{ 0 };
int g_iPlayerMaxFrames{ 0 };

//Trigger
bool g_bIsRenderDamagePlayer{ false };

void renderCharacterDamage(Console& console, Player& plr, int enemyDMG) {

	if (!g_bIsRenderDamagePlayer)
		return;

	switch (g_iPlayerFrameNumber) {
	case 0:
		plr.renderColour = COLOURS::WHITE;
		break;
	case 5:
		plr.renderColour = COLOURS::RED;
		break;
	case 10:
		plr.renderColour = COLOURS::RED;
		break;
	default:
		break;
	}

	int damage = enemyDMG;
	if (plr.isDefend)
		damage *= 0.7;

	console.writeToBuffer(25, 15, std::to_string(damage));

	// End of render
	if (g_iPlayerCurrentFrame == g_iPlayerMaxFrames)
	{
		// Reset values
		g_iPlayerCurrentFrame = 0;
		g_iPlayerFrameNumber = 0;
		g_bIsRenderDamagePlayer = false;
		plr.isDefend = false;
	}

	g_iPlayerCurrentFrame++;
	++g_iPlayerFrameNumber %= 10;
}

void triggerRenderPlayerDamage() {

	if (g_bIsRenderDamagePlayer)
		return;

	g_bIsRenderDamagePlayer = true;
	g_iPlayerMaxFrames = 20;
}