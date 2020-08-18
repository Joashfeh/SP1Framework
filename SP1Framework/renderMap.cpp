#include "renderMap.h"
#include "Player.h"
#include "Map.h"

void renderMap(Console& g_Console, Player& plr, Map& map)
{

    int row = plr.Pos.row - 12;
    int col = plr.Pos.col - 32;

    // Set up sample colours, and output shadings
    const WORD colors[] = {
        0, 255
    };

    COORD c;
    for (int y = 0; y < 24; ++y) {
        for (int x = 0; x < 64; ++x) {
            c.X = x;
            c.Y = y;

            if (map.fullMap[row][col] == 0) g_Console.writeToBuffer(c, ' ');
            if (map.fullMap[row][col] == 1) g_Console.writeToBuffer(c, '*');

            col++;

        }
        col = plr.Pos.col - 32;
        row++;
    }
}