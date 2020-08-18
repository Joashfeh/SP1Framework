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
            case 0:
                g_Console.writeToBuffer(c, '*', colors[0]);
                break;
            case 1:
                g_Console.writeToBuffer(c, ' ', colors[1]);
                break;
            }

            c.X++;   
        }
        c.X = 0;
        c.Y++;
    }
}