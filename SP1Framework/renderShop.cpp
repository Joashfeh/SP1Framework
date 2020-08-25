#include "renderShop.h"
#include "Player.h"

void renderShop(Console& g_Console, Player& plr)
{
    renderShopinterface(g_Console, plr);
    renderConfirmation(g_Console);
}
