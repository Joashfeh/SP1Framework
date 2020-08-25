#include "renderShop.h"
#include "Player.h"

void renderShop(Console& g_Console, Player& ptr)
{
    renderShopinterface(g_Console, ptr);
    renderConfirmation(g_Console);
}
