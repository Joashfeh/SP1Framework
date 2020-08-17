#include "renderMap.h"
#include "Player.h"
#include "Map.h"

void renderMap(Console& g_Console, Player& plr, Map& map)
{
    // Set up sample colours, and output shadings
    const WORD colors[] = {
        0, 255
    };

    int row;
    int col;

    COORD c;
    for (int y = 0; y < 25; ++y) {
        for (int x = 0; x < 65; ++x) {
            c.X = x;
            c.Y = y;

            row = plr.Pos.row - 12;
            col = plr.Pos.col - 24;

            if (map.fullMap[row][col] == 0) g_Console.writeToBuffer(c, ' ');
            if (map.fullMap[row][col] == 1) g_Console.writeToBuffer(c, '*');



        }
    }
}