#pragma once
#include "game.h"
#include "Player.h"
#include "Map.h"
#include "Framework\timer.h"

struct DIRECTION {
    bool UP;
    bool RIGHT;
    bool DOWN;
    bool LEFT;
};
// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    DIRECTION moving;
    bool  m_bActive;
};

void renderCharacter(SGameChar& g_sChar, Console& g_Console);     // renders the character into the buffer
void moveChar(SGameChar &g_sChar, Player &plr, Map& map);