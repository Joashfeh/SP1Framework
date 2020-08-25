#pragma once
#include "Interface.h"
#include "keyEvents.h"
#include "Weapon.h"
#include "Armor.h"

struct ConfirmationBox {
public:
	static bool appear;
	static bool yes;
	static bool no;
	static bool itemToBuy[8];
};


void renderShopinterface(Console& g_Console/*, int* gold_input*/);// renders the shop interface
void insertWeapon(Console& g_Console, int x, int y, Weapon weapon);// puts the weapon information into the shop
void insertArmour(Console& g_Console, int x, int y, Armor armor);// puts the armor information into the shop
void confirmationBox(Console& g_Console);// confirms whether the user wants to buy the item
void renderConfirmation(Console& g_Console);//renders the confirmation displpay
std::string checkItem(int id);// checks item that player wants to buy