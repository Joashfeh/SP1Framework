#include "renderBattle.h"

void renderBattle(double& dt, Console& g_Console, Player& plr, Enemy& enemy) {
    renderCharacterSprite(g_Console, 5, 15, plr, dt);
    renderEnemySprite(g_Console, 113, 15, enemy);
    renderEnemyDamage(g_Console, enemy);
    renderCharacterDamage(g_Console, plr);
    battleInterface(g_Console);
    renderPlayerStats(g_Console, plr);
    renderEnemyStats(g_Console, enemy);
}