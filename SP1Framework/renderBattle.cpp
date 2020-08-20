#include "renderBattle.h"

void renderBattle(double& g_dElapsedTime, Console& g_Console, Player& plr) {

    loadCharacter(g_Console, 5, 15, plr);
    renderCharacterDamage(g_Console, plr);
    battleInterface(g_Console);
    renderPlayerStats(g_Console, plr);
}

void battleKBHandler(const KEY_EVENT_RECORD& keyboardEvent, SKeyEvent* g_skKeyEvent) {
    EKEYS key = K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case VK_LEFT: key = K_LEFT; break;
    case VK_RIGHT: key = K_RIGHT; break;
    case VK_SPACE: key = K_SPACE; break;
    case VK_ESCAPE: key = K_ESCAPE; break;
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != K_COUNT)
    {
        g_skKeyEvent[key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[key].keyReleased = !keyboardEvent.bKeyDown;
    }
}

