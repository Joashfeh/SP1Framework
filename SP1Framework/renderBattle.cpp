#include "renderBattle.h"

void renderBattle(double& dt, Console& g_Console, Player& plr, Enemy& enemy, int turn_here) {
    renderCharacterSprite(g_Console, 5, 15, plr, dt);
    renderCharacterDamage(g_Console, plr, enemy.Damage);
    renderEnemySprite(g_Console, 113, 8, enemy, turn_here);
    renderEnemyDamage(g_Console, enemy, plr);
    battleInterface(g_Console);
    renderPlayerStats(g_Console, plr);
    renderEnemyStats(g_Console, enemy);
}