#include "renderMainMenu.h"
#include <fstream>
#include <string>
#include "renderLevelTransition.h"

void renderMainMenu(Console& g_Console) {
	std::string menuData = "MainMenu_data/Menu_screen.txt";

	// Open file
	std::ifstream menuScreen(menuData, std::ios::in);
	if (!menuScreen)
		return;

	COORD outputCoord;
	outputCoord.X = 0;
	outputCoord.Y = 0;

	for (int i = 0; i < 40; i++) {
		std::string a;
		std::getline(menuScreen, a);

		g_Console.writeToBuffer(outputCoord, a);
		outputCoord.Y++;
	}

	menuScreen.close();

}
