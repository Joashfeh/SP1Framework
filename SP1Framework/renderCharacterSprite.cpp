#include "renderCharacterSprite.h"
#include "colours.h"
#include <fstream>
#include <string>

int charSprite = 1;

void renderCharacterSprite(Console& console, short x, short y, Player& plr, double dt) {
	COORD c;
	c.X = x;
	c.Y = y;

	renderCharacterSprite(console, c, plr, dt);
}

void renderCharacterSprite(Console& console, COORD c, Player& plr, double dt) {

	int x = c.X;
	int y = c.Y;

	plr.frameTimer += dt;

	if (plr.frameTimer > 0.5 && charSprite == 1) { charSprite = 2; plr.frameTimer = 0; }
	if (plr.frameTimer > 0.5 && charSprite == 2) { charSprite = 1; plr.frameTimer = 0; }

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