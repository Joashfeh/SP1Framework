#include "renderShop.h"

void renderShop(Console& g_Console)
{
    renderShopinterface(g_Console);
    renderShopEvents();
    renderConfirmation(g_Console);
}
