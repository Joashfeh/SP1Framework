#include "loadCharacter.h"
#include "colours.h"
#include <fstream>
#include <string>

int g_iCurrentFrame{ 0 };
static int g_iFrameNumber{ 0 };
int g_iMaxFrames{ 0 };
int charSprite = 1;

void loadCharacter(Console& console, short x, short y, Player& plr) {
	COORD c;
	c.X = x;
	c.Y = y;

	loadCharacter(console, c, plr);
}

void loadCharacter(Console &console, COORD c, Player& plr) {

	int x = c.X;
	int y = c.Y;

	switch (g_iFrameNumber) {
	case 0:
		charSprite = 1;
		break;
	case 8:
		charSprite = 2;
		break;
	default:
		break;
	}

	g_iCurrentFrame++;
	++g_iFrameNumber %= 16;

	std::string spriteNo = "Sprite_data/Player_0";
	spriteNo += std::to_string(charSprite);
	spriteNo += ".txt";

	std::ifstream spriteData(spriteNo, std::ios::in);
	if (!spriteData)
		return;

	COLOURS outputColour = plr.renderColour;

	for (int row = 0; row < 8; row++) {
		std::string outputString;
		std::getline(spriteData, outputString);

		for (int col = 0; col < 8; col++) {

			switch (outputString[col]) {
			case '0':
				outputColour = COLOURS::BLACK;
				break;
			default:
				outputColour = plr.renderColour;
				break;
			}

			console.writeToBuffer(c, ' ', outputColour); c.X++;
			console.writeToBuffer(c, ' ', outputColour); c.X++;
		}
		c.Y++;
		c.X = x;
	}

	spriteData.close();

}