#include "renderEnemySprite.h"
#include <fstream>
#include "colours.h"

void renderEnemySprite(Console& console, short x, short y, Enemy& enemy, int level_input) {
	COORD c;
	c.X = x;
	c.Y = y;

	renderEnemySprite(console, c, enemy, level_input);
}

void renderEnemySprite(Console& console, COORD c, Enemy& enemy, int current_level) {

	int x = c.X;
	int y = c.Y;

	//std::string spriteNo = "Sprite_data/Enemy2.txt";
	std::string spriteNo = "Enemy_data/level_";
	spriteNo += std::to_string(current_level);
	spriteNo += "/sprite_data/enemy_";
	spriteNo += std::to_string(enemy.enemy_no);
	spriteNo += ".txt";

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
