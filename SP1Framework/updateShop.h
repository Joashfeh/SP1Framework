#pragma once
#include "keyEvents.h"
#include "shopInterface.h"
#include "Player.h"

void checkBuyButton(SMouseEvent& g_mouseEvent, int x, int y, int itemID);
void checkNoButton(SMouseEvent& g_mouseEvent);
void checkYesButton(SMouseEvent& g_mouseEvent, Player& plr);
bool checkGold(int ID, Player& plr);
void checkOKButton(SMouseEvent& g_mouseEvent);

void updateShop(Console& g_Console, SMouseEvent& g_mouseEvent, SKeyEvent* g_skKeyEvent, EGAMESTATES& g_eGameState, Player& plr);