#include "renderGameOver.h"
#include "game.h"
#include <fstream>
#include <string>

void renderGameOver(Console& g_Console) {

	std::ifstream gameOverText("GameOver_data/game_over.txt", std::ios::in);
	if (!gameOverText)
		return;

	COORD outputCoord;
	std::string a;
	outputCoord.Y = g_Console.getConsoleSize().Y / 2 - 3;

	for (int i = 0; i < 8; i++) {
		std::getline(gameOverText, a);

		outputCoord.X = g_Console.getConsoleSize().X / 2 - a.length() / 2;
		g_Console.writeToBuffer(outputCoord, a);
		outputCoord.Y++;
	}

}
