#include "Interface.h"

void displayBoxes(Console& g_Console, int x, int y, int width, int height)
{
	COORD c;
	c.X = x;
	c.Y = y;
	std::string outputString;

	for (int i = 0; i < height; i++) {
		outputString = "";

		if (i == 0) {
			outputString += (char)201;
			outputString += std::string(width - 2, (char)205);
			outputString += (char)187;
		}
		else if (i == height - 1) {
			outputString += (char)200;
			outputString += std::string(width - 2, (char)205);
			outputString += (char)188;
		}
		else {
			outputString += (char)186;
			outputString += std::string(width - 2, ' ');
			outputString += (char)186;
		}

		g_Console.writeToBuffer(c, outputString);
		c.Y++;
	}
}

void displayBoxes(Console& g_Console, COORD outputC, int width, int height) {
	int x = outputC.X;
	int y = outputC.Y;
	displayBoxes(g_Console, x, y, width, height);
}

void mainDisplay(Console& g_Console)
{
	COORD c;
	c.Y = 0;
	c.X = 0;
	for (int row = 0; row < 40; row++)
	{
		for (int col = 0; col < 120; col++)
		{
			if (c.Y == 0)
				g_Console.writeToBuffer(c, (char)219);

			else if (c.Y == 39)
				g_Console.writeToBuffer(c, (char)219);
			else
			{
				if ((c.X == 0) || (c.X == 118))
				{
					g_Console.writeToBuffer(c, (char)219);
					c.X++;
					g_Console.writeToBuffer(c, (char)219);
					c.X--;
				}
			}
			c.X++;
		}
		c.X = 0;
		c.Y++;
	}
}

