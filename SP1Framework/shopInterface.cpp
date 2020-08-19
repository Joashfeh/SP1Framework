#include "shopInterface.h"
void renderShopinterface(Console& g_Console)
{

    mainDisplay(g_Console);
    displayBoxes(g_Console, 22, 1, 21, 5, (char)177);
    g_Console.writeToBuffer(28, 3, "THE SHOP!");

    displayBoxes(g_Console, 2, 7, 25, 16, (char)177);
    g_Console.writeToBuffer(6, 9, "Weapons or smthg");
    displayBoxes(g_Console, 4, 8, 21, 3, (char)176);

    displayBoxes(g_Console, 38, 7, 25, 16, (char)177);
    g_Console.writeToBuffer(43, 9, "Armour or smthg");
    displayBoxes(g_Console, 40, 8, 21, 3, char(176));
}
