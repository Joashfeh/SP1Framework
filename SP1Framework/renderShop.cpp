#include "renderShop.h"

void renderShop(Console& g_Console, Player& plr)
{
    //Player* gold_get;
    renderShopinterface(g_Console, plr);
    renderConfirmation(g_Console);
}
