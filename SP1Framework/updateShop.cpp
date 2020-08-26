#include "updateShop.h"



void checkBuyButton(SMouseEvent& g_mouseEvent, int x, int y, int itemID)
{
    for (int i = 0; i < 3; i++)
    {
        if ((g_mouseEvent.mousePosition.X == x + i) && (g_mouseEvent.mousePosition.Y == y))
        {
            if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                ConfirmationBox::appear = true;
                ConfirmationBox::itemToBuy[itemID] = true;
            }
        }
    }
}

void checkNoButton(SMouseEvent& g_mouseEvent)
{

    if (ConfirmationBox::appear == true)
    {
        for (int i = 0; i < 2; i++)
        {
            if ((g_mouseEvent.mousePosition.X == 64 + i) && (g_mouseEvent.mousePosition.Y == 21))
                if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    ConfirmationBox::no = true;
        }
    }


    if (ConfirmationBox::no == true)
    {
        ConfirmationBox::appear = false;
        ConfirmationBox::no = false;
        for (int i = 0; i < 8; i++)
        {
            ConfirmationBox::itemToBuy[i] = false;
        }

    }
}

void checkYesButton(SMouseEvent& g_mouseEvent, Player& plr)
{
    if (ConfirmationBox::appear == true)
    {
        for (int i = 0; i < 3; i++)
        {
            if ((g_mouseEvent.mousePosition.X == 57 + i) && (g_mouseEvent.mousePosition.Y == 21))
                if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    ConfirmationBox::yes = true;
        }
    }

    if (ConfirmationBox::yes == true) {
        ConfirmationBox::appear = false;
        ConfirmationBox::yes = false;
        for (int i = 0; i < 8; i++) {
            if (ConfirmationBox::itemToBuy[i] == true) {
                if (checkGold(i, plr) == true) {
                    if (i < 5) {//if weapon load weapon
                        plr.mainWeapon.loadWeapon(i + 1);
                        ConfirmationBox::itemBought[0] = true;
                    }
                    else
                    {//if armor load armor
                        plr.mainArmor.loadArmor(i - 4);
                        if (plr.HP <= 100) {
                            plr.HP += plr.mainArmor.armorHealth;
                        }
                        else if (plr.HP > 100) {
                            plr.HP = 100 + plr.mainArmor.armorHealth;
                        }
                        if (plr.Defense <= 30) {
                            plr.Defense += plr.mainArmor.defence;
                        }
                        else if (plr.Defense > 30) {
                            plr.Defense = 30 + plr.mainArmor.defence;
                        }
                        ConfirmationBox::itemBought[1] = true;
                    }
                }
                else
                    ConfirmationBox::rejection = true;
                
                ConfirmationBox::itemToBuy[i] = false;
            }
        }
    }


}

bool checkGold(int ID, Player& plr)
{
    if (ID < 5)
    {
        Weapon toBuy(ID + 1);
        if (plr.gold >= toBuy.cost)
        {
            plr.gold -= toBuy.cost;
            return true;
        }
        else
            return false;
    }

    else
    {
        Armor toBuy(ID - 4);
        if (plr.gold >= toBuy.cost)
        {
            plr.gold -= toBuy.cost;
            return true;
        }
        else
            return false;
    }
}

void checkOKButton(SMouseEvent& g_mouseEvent)
{
    if (ConfirmationBox::rejection == true)
    {
        for (int i = 0; i < 2; i++)
        {
            if ((g_mouseEvent.mousePosition.X == 61 + i) && (g_mouseEvent.mousePosition.Y == 21))
                if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    ConfirmationBox::rejection = false;
        }
    }
}

void updateShop(Console& g_Console, SMouseEvent& g_mouseEvent, SKeyEvent* g_skKeyEvent,EGAMESTATES& g_eGameState, Player& plr)
{
    if (g_skKeyEvent[K_SHOP].keyDown)
    {
        ConfirmationBox::appear = false;
        ConfirmationBox::rejection = false;
        for (int i = 0; i < 8; i++)
            ConfirmationBox::itemToBuy[i] = false;
        ConfirmationBox::itemBought[1] = false;
        ConfirmationBox::itemBought[0] = false;
        g_eGameState = S_GAME;
    }

    checkNoButton(g_mouseEvent);
    checkYesButton(g_mouseEvent, plr);
    checkOKButton(g_mouseEvent);

    if ((ConfirmationBox::appear == false) 
        && (ConfirmationBox::itemBought[0] == false)
        && (ConfirmationBox::itemBought[1] == false))

    {//prevents buying of another item if player is in the middle of buying
        checkBuyButton(g_mouseEvent, 47, 15, 0);
        checkBuyButton(g_mouseEvent, 47, 19, 1);
        checkBuyButton(g_mouseEvent, 47, 23, 2);
        checkBuyButton(g_mouseEvent, 47, 27, 3);
        checkBuyButton(g_mouseEvent, 47, 31, 4);

        checkBuyButton(g_mouseEvent, 108, 15, 5);
        checkBuyButton(g_mouseEvent, 108, 23, 6);
        checkBuyButton(g_mouseEvent, 108, 31, 7);
    }
}