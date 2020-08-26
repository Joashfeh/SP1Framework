#include "battleInterface.h"
#include "Interface.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

void battleInterface(Console& g_Console) {

    COORD outputCoord;

    outputCoord.X = 0;
    outputCoord.Y = 25;

    for (int row = 0; row < 15; row++) {
        for (int col = 0; col < 120; col++) {
            g_Console.writeToBuffer(outputCoord, '+');
            outputCoord.X++;
        }
        outputCoord.Y++;
        outputCoord.X = 0;
    }

    outputCoord.X = 5;
    outputCoord.Y = 26;
    g_Console.writeToBuffer(outputCoord, "                              ");
    outputCoord.Y++; g_Console.writeToBuffer(outputCoord, "                              ");
    outputCoord.Y++; g_Console.writeToBuffer(outputCoord, "                              ");

    outputCoord.X = 7;
    outputCoord.Y = 27;

    g_Console.writeToBuffer(outputCoord, "What would you like to do?");

    std::ifstream attackStr("Battle_data/Attack.txt", std::ios::in);
    if (!attackStr)
        return;

    std::ifstream defendStr("Battle_data/Defend.txt", std::ios::in);
    if (!defendStr)
        return;

    outputCoord.X = 5;
    outputCoord.Y = 30;
    for (int row = 0; row < 8; row++) {
        std::string outputStr;
        std::getline(attackStr, outputStr);

        g_Console.writeToBuffer(outputCoord, outputStr);
        outputCoord.Y++;

    }

    outputCoord.X = 67;
    outputCoord.Y = 30;
    for (int row = 0; row < 8; row++) {
        std::string outputStr;
        std::getline(defendStr, outputStr);

        g_Console.writeToBuffer(outputCoord, outputStr);
        outputCoord.Y++;

    }

}

void renderPlayerStats(Console& g_Console, Player& plr) {
    COORD outputCoord;
    outputCoord.X = 2;
    outputCoord.Y = 1;

    displayBoxes(g_Console, outputCoord, 23, 7);

    outputCoord.X = 4;
    outputCoord.Y = 2;

    std::ostringstream outputString; 
    outputString << "Health : " << plr.HP << " / " << plr.maxHealth;
    g_Console.writeToBuffer(outputCoord,  outputString.str());

    outputString.str("");
    outputCoord.Y += 2;
    outputString << "Attack : " << plr.Damage << " + " << plr.mainWeapon.dmg;
    g_Console.writeToBuffer(outputCoord, outputString.str());

    outputString.str("");
    outputCoord.Y += 2;
    outputString << "Defense : " << plr.Defense << " / " << plr.maxArmor;
    g_Console.writeToBuffer(outputCoord, outputString.str());

}

void renderEnemyStats(Console& g_Console, Enemy& enemy) {
    COORD outputCoord;
    outputCoord.X = 95;
    outputCoord.Y = 1;

    displayBoxes(g_Console, outputCoord, 23, 7);

    outputCoord.X = 97;
    outputCoord.Y = 2;

    std::ostringstream outputString;
    outputString << "Health : " << enemy.HP;
    g_Console.writeToBuffer(outputCoord, outputString.str());

    outputString.str("");
    outputCoord.Y += 2;
    outputString << "Attack : " << enemy.Damage;
    g_Console.writeToBuffer(outputCoord, outputString.str());

    outputString.str("");
    outputCoord.Y += 2;
    outputString << "Defense : " << enemy.Defense;
    g_Console.writeToBuffer(outputCoord, outputString.str());

}
