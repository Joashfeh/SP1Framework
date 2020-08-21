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

    outputCoord.X = 1;
    outputCoord.Y = 26;

    g_Console.writeToBuffer(outputCoord, "What would you like to do?");

    std::ifstream attackStr("Battle_data/Attack.txt", std::ios::in);
    if (!attackStr)
        return;

    std::ifstream defendStr("Battle_data/Defend.txt", std::ios::in);
    if (!defendStr)
        return;

    outputCoord.X = 1;
    outputCoord.Y = 28;
    for (int row = 0; row < 8; row++) {
        std::string outputStr;
        std::getline(attackStr, outputStr);

        g_Console.writeToBuffer(outputCoord, outputStr);
        outputCoord.Y++;

    }

    outputCoord.X = 72;
    outputCoord.Y = 28;
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
    outputString << "Health : " << plr.HP << " / 100";
    g_Console.writeToBuffer(outputCoord,  outputString.str());

    outputString.str("");
    outputCoord.Y += 2;
    outputString << "Attack : " << plr.Damage;
    g_Console.writeToBuffer(outputCoord, outputString.str());

    outputString.str("");
    outputCoord.Y += 2;
    outputString << "Defense : " << plr.Defense;
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