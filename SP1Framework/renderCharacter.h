#pragma once
#include "game.h"
#include "Player.h"
#include "Map.h"
#include "Framework\timer.h"

enum DIRECTION {
    UP = 'U',
    RIGHT = 'R',
    DOWN = 'D',
    LEFT = 'L',
    NONE = 'N'
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    DIRECTION dir = NONE;
    bool  m_bActive;
    bool  moving;
};

void renderCharacter(SGameChar& g_sChar, Console& g_Console);     // renders the character into the buffer
void moveChar(SGameChar &g_sChar, Player &plr, Map& map);