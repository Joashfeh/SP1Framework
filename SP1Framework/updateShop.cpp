#include "updateShop.h"



void checkBuyButton(SMouseEvent& g_mouseEvent, int x, int y, int itemID)
{
    for (int i = 0; i < 3; i++)
    {
        if ((g_mouseEvent.mousePosition.X == x + i) && (g_mouseEvent.mousePosition.Y == y))
        {
            if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                ConfirmationBox::appear = true;
            ConfirmationBox::itemToBuy[itemID] = true;
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
            if (ConfirmationBox::itemToBuy[i] == true)
                ConfirmationBox::itemToBuy[i] = false;
        }
    }
}

void checkYesButton(SMouseEvent& g_mouseEvent)
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

    if (ConfirmationBox::yes == true)
    {
        ConfirmationBox::appear = false;
        ConfirmationBox::yes = false;
        for (int i = 0; i < 8; i++)
        {
            if (ConfirmationBox::itemToBuy[i] == true)
                ConfirmationBox::itemToBuy[i] = false;
        }
    }


}

void updateShop(Console& g_Console, SMouseEvent& g_mouseEvent, SKeyEvent* g_skKeyEvent,EGAMESTATES& g_eGameState)
{
    if (g_skKeyEvent[K_SHOP].keyDown)
    {
        g_eGameState = S_GAME;
    }

    checkNoButton(g_mouseEvent);
    checkYesButton(g_mouseEvent);

    checkBuyButton(g_mouseEvent, 47, 15, 0);
    checkBuyButton(g_mouseEvent, 47, 19, 1);
    checkBuyButton(g_mouseEvent, 47, 23, 2);
    checkBuyButton(g_mouseEvent, 47, 27, 3);
    checkBuyButton(g_mouseEvent, 47, 32, 4);

    checkBuyButton(g_mouseEvent, 108, 15, 5);
    checkBuyButton(g_mouseEvent, 108, 23, 6);
    checkBuyButton(g_mouseEvent, 108, 31, 7);
}