#pragma once
#include "Interface.h"
#include "keyEvents.h"
#include "Weapon.h"
#include "Armor.h"

class ConfirmationBox {
public:
	static bool appear;
	static bool yes;
	static bool no;
};


void renderShopinterface(Console& g_Console);
void insertWeapon(Console& g_Console, int x, int y, Weapon weapon);
void insertArmour(Console& g_Console, int x, int y, Armor armor);
void confirmationBox(Console& g_Console);
void renderConfirmation(Console& g_Console);