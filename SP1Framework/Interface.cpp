#include "Interface.h"

void displayBoxes(Console& g_Console, int x, int y, int l, int h, char s)
{
	COORD c;
	c.X = x;
	c.Y = y;
	for (int col = 0; col < h; col++)
	{
		for (int row = 0; row < l; row++)
		{
			if (c.Y == y)
				g_Console.writeToBuffer(c, s);
			else if (c.Y == y + h - 1)
				g_Console.writeToBuffer(c, s);
			else
			{
				if ((c.X == x) || (c.X == x + l - 2))
				{
					g_Console.writeToBuffer(c, s);
					c.X++;
					g_Console.writeToBuffer(c, s);
					c.X--;
				}
			}
			c.X++;

		}
		c.X = x;
		c.Y++;
	}
}

void mainDisplay(Console& g_Console)
{
	COORD c;
	c.Y = 0;
	c.X = 0;
	for (int row = 0; row < 24; row++)
	{
		for (int col = 0; col < 65; col++)
		{
			if (c.Y == 0)
				g_Console.writeToBuffer(c, (char)219);

			else if (c.Y == 23)
				g_Console.writeToBuffer(c, (char)219);
			else
			{
				if ((c.X == 0) || (c.X == 63))
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

