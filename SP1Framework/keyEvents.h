#pragma once
#include "Player.h"
#include "Framework/console.h"
#include "renderCharacter.h"
#include "Map.h"
#include "game.h"

struct SKeyEvent
{
    bool keyDown;
    bool keyReleased;
};

struct SMouseEvent
{
    COORD mousePosition;
    DWORD buttonState;
    DWORD eventFlags;
};

enum EKEYS
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_SHOP,
    K_ESCAPE,
    K_SPACE,
    K_COUNT
};

