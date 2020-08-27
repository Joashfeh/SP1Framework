#include "renderLevelTransition.h"
#include "colours.h"
#include <sstream>

int frameNumber{ 0 };
int maxFrames{ 360 };

int endRow{ 0 };
bool screenTransition{ false };

void renderLevelTransition(Console& g_Console, EGAMESTATES& g_eGameState, Map& map) {

	if (!screenTransition)
		return;

	COLOURS renderColour = COLOURS::BLACK;

	if (frameNumber == maxFrames) {
		frameNumber = 0;
		endRow = 0;
		screenTransition = false;
		g_eGameState = S_GAME;
		return;
	}

	for (int row = 0; row < endRow; row++) {
		for (int col = 0; col < 140; col++) {
			g_Console.writeToBuffer(col, row, ' ', renderColour);
		}
	}

	if (frameNumber > 80 && frameNumber < 180) {
		std::ostringstream ss;
		ss << "Floor " << map.floor;
		g_Console.writeToBuffer(g_Console.getConsoleSize().X / 2 - ss.str().length() / 2, g_Console.getConsoleSize().Y / 2, ss.str());
	}

	if (frameNumber >= 120)
		endRow--;

	if (frameNumber < 120)
		endRow++;
	
	frameNumber++;

}

void triggerLevelTransition() {
	screenTransition = true;
}
