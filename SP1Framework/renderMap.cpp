#include "renderMap.h"
#include "Player.h"
#include "Map.h"

void renderMap(Console& g_Console, Player& plr, Map& map)
{

    // Set up sample colours, and output shadings
    const WORD colors[] = {
        0, 255
    };

    COORD c;
    c.X = 0;
    c.Y = 0;

    for (int row = plr.Pos.row - 12; row < plr.Pos.row + 12; row++) {
        for (int col = plr.Pos.col - 32; col < plr.Pos.col + 32; col++) {

            switch (map.display[row][col]) {
            case MAPTILE::EMPTYTILE:
                g_Console.writeToBuffer(c, ' ', colors[0]);
                break;
            case MAPTILE::WALL:
                g_Console.writeToBuffer(c, (char)176);
                break;
            }

            c.X++;   
        }
        c.X = 0;
        c.Y++;
    }
}