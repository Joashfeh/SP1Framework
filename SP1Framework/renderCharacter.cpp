#include "renderCharacter.h"
#include "colours.h"

void renderCharacter(SGameChar &g_sChar, Console &g_Console)
{
    // Draw the location of the character
    COLOURS charColor = COLOURS::BLACKMIDDLEBLUE;
    unsigned char playerChar = 254;
    COORD c = g_sChar.m_cLocation;
    g_Console.writeToBuffer(c, playerChar, charColor);
}

void moveChar(SGameChar& g_sChar, Player& plr, Map& map, double dt) {

    g_sChar.frameTimer += dt;

    if (!g_sChar.canMove)
        return;

    if (g_sChar.frameTimer < 0.05)
        return;

    g_sChar.frameTimer = 0;

    switch (g_sChar.moving.UP) {
    case true:
        if (map.display[plr.Pos.row - 1][plr.Pos.col] != '1' && map.display[plr.Pos.row - 1][plr.Pos.col] != '3') 
            plr.Pos.row -= 1;
        break;
    case false:
        break;
    }

    switch (g_sChar.moving.RIGHT) {
    case true:
        if (map.display[plr.Pos.row][plr.Pos.col + 1] != '1' && map.display[plr.Pos.row][plr.Pos.col + 1] != '3') 
            plr.Pos.col += 1;
        break;
    case false:
        break;
    }

    switch (g_sChar.moving.DOWN) {
    case true:
        if (map.display[plr.Pos.row + 1][plr.Pos.col] != '1' && map.display[plr.Pos.row + 1][plr.Pos.col] != '3') 
            plr.Pos.row += 1;
        break;
    case false:
        break;
    }

    switch (g_sChar.moving.LEFT) {
    case true:
        if (map.display[plr.Pos.row][plr.Pos.col - 1] != '1' && map.display[plr.Pos.row][plr.Pos.col - 1] != '3') 
            plr.Pos.col -= 1;
        break;
    case false:
        break;
    }
    
}
