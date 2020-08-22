#include "updateShop.h"



void checkBuyButton(SMouseEvent& g_mouseEvent, int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        if ((g_mouseEvent.mousePosition.X == x + i) && (g_mouseEvent.mousePosition.Y == y))
        {
            if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                ConfirmationBox::appear = true;
            }
        }
    }
}

void updateShop(Console& g_Console, SMouseEvent& g_mouseEvent, SKeyEvent* g_skKeyEvent,EGAMESTATES& g_eGameState)
{
    if (g_skKeyEvent[K_SHOP].keyDown)
    {
        g_eGameState = S_GAME;
    }
    if (ConfirmationBox::appear == true)
        confirmationBox(g_Console);


    if (ConfirmationBox::appear == true)
    {
        for (int i = 0; i < 2; i++)
        {
            if ((g_mouseEvent.mousePosition.X == 64 + i) && (g_mouseEvent.mousePosition.Y == 21))
            {
                if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                {
                    ConfirmationBox::no = true;
                }
            }
        }
    }

    checkBuyButton(g_mouseEvent, 47, 15);
    checkBuyButton(g_mouseEvent, 47, 19);
    checkBuyButton(g_mouseEvent, 47, 23);
    checkBuyButton(g_mouseEvent, 47, 27);
    checkBuyButton(g_mouseEvent, 47, 32);

    checkBuyButton(g_mouseEvent, 108, 15);
    checkBuyButton(g_mouseEvent, 108, 23);
    checkBuyButton(g_mouseEvent, 108, 31);
}