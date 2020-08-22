#pragma once
#include "keyEvents.h"
#include "shopInterface.h"

void checkBuyButton(SMouseEvent& g_mouseEvent, int x, int y);

void updateShop(Console& g_Console, SMouseEvent& g_mouseEvent, SKeyEvent* g_skKeyEvent, EGAMESTATES& g_eGameState);