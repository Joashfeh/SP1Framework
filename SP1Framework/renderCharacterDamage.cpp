#pragma once
#include "renderCharacterDamage.h"

int g_iDamageCurrentFrame{ 0 };
static int g_iDamageFrameNumber{ 0 };
int g_iDamageMaxFrames{ 0 };

//Trigger
bool g_bIsRenderDamagePlayer{ false };

void renderCharacterDamage(Console& console, Player& plr) {

	if (g_bIsRenderDamagePlayer == false)
		return;

	switch (g_iDamageFrameNumber) {
	case 0:
		plr.renderColour = COLOURS::WHITE;
		break;
	case 4:
		plr.renderColour = COLOURS::RED;
		break;
	default:
		break;
	}

	// End of render
	if (g_iDamageCurrentFrame == g_iDamageMaxFrames)
	{
		//Reset values
		g_iDamageCurrentFrame = 0;
		g_iDamageFrameNumber = 0;
		g_bIsRenderDamagePlayer = false;
	}

	g_iDamageCurrentFrame++;
	++g_iDamageFrameNumber %= 8;

}

void triggerRenderPlayerDamage() {

	if (g_bIsRenderDamagePlayer)
		return;

	g_bIsRenderDamagePlayer = true;
	g_iDamageMaxFrames = 16;
}