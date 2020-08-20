#include "renderMap.h"
#include "Player.h"
#include "Map.h"
#include "colours.h"

void renderMap(Console& g_Console, Player& plr, Map& map)
{

    // Set up sample colours, and output shadings
    

    COORD c;
    c.X = 0;
    c.Y = 0;

    for (int row = plr.Pos.row - 20; row < plr.Pos.row + 20; row++) {
        for (int col = plr.Pos.col - 60; col < plr.Pos.col + 60; col++) {

            COLOURS colour;
            colour = COLOURS::DEFAULT;

            unsigned char outputChar = ' ';

            switch (map.display[row][col]) {
            case MAPTILE::EMPTYTILE:
                outputChar = ' ';
                break;
            case MAPTILE::WALL:
                outputChar = 176;
                break;
            case MAPTILE::ENEMYSPAWN:
                outputChar = 158;
                colour = COLOURS::BLACKDARKGREY;
                break;
            case MAPTILE::LADDER:
                outputChar = 206;
                c.Y--; g_Console.writeToBuffer(c, outputChar, colour);
                c.Y--; g_Console.writeToBuffer(c, outputChar, colour);
                c.Y += 2;
                break;
            }

            g_Console.writeToBuffer(c, outputChar, colour);
            c.X++;   
        }
        c.X = 0;
        c.Y++;
    }
}