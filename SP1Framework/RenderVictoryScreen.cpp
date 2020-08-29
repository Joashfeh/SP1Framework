#include "RenderVictoryScreen.h"
#include <fstream>
#include <string>

void renderVictoryScreen(Console& g_Console) {
	std::string VictoryData = "renderVictory_data/Victory_screen.txt";

	// Open file
	std::ifstream VictoryScreen(VictoryData, std::ios::in);
	if (!VictoryScreen)
		return;

	COORD outputCoord;
	outputCoord.X = 0;
	outputCoord.Y = 0;

	for (int i = 0; i < 40; i++) {
		std::string a;
		std::getline(VictoryScreen, a);

		g_Console.writeToBuffer(outputCoord, a);
		outputCoord.Y++;
	}

	VictoryScreen.close();

}