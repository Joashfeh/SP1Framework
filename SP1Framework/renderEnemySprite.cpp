#include "renderEnemySprite.h"
#include <fstream>
#include "colours.h"

void renderEnemySprite(Console& console, short x, short y, Enemy& enemy) {
	COORD c;
	c.X = x;
	c.Y = y;

	renderEnemySprite(console, c, enemy);
}

void renderEnemySprite(Console& console, COORD c, Enemy& enemy) {

	int x = c.X;
	int y = c.Y;

	std::string spriteNo = "Sprite_data/Enemy2.txt";

	std::ifstream spriteData(spriteNo, std::ios::in);
	if (!spriteData)
		return;

	COLOURS outputColour = enemy.renderColour;

	for (int row = 15; row >= 0; row--) {
		std::string outputString;
		std::getline(spriteData, outputString);

		for (int col = 15; col >= 0; col--) {

			switch (outputString[col]) {
			case '0':
				outputColour = COLOURS::BLACK;
				break;
			default:
				outputColour = enemy.renderColour;
				break;
			}

			console.writeToBuffer(c, ' ', outputColour); c.X--;
			console.writeToBuffer(c, ' ', outputColour); c.X--;
		}
		c.Y++;
		c.X = x;
	}

	spriteData.close();

}
