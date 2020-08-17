#include "renderCharacter.h"

void renderCharacter(SGameChar &g_sChar, Console &g_Console)
{
    // Draw the location of the character
    WORD charColor = 0x0C;
    if (g_sChar.m_bActive)
    {
        charColor = 0x0A;
    }
    COORD c = g_sChar.m_cLocation;
    g_Console.writeToBuffer(c, (char)1, charColor);
}