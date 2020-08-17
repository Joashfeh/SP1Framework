#pragma once
#include "game.h"
#include "Framework\timer.h"

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    bool  m_bActive;
};

void renderCharacter(SGameChar& g_sChar, Console& g_Console);     // renders the character into the buffer