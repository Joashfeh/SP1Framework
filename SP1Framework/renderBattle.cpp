#include "renderBattle.h"

void renderBattle(double& dt, Console& g_Console, Player& plr, Enemy& enemy) {
    renderCharacterSprite(g_Console, 5, 15, plr, dt);
    renderCharacterDamage(g_Console, plr, enemy.Damage);
    renderEnemySprite(g_Console, 113, 15, enemy);
    renderEnemyDamage(g_Console, enemy, plr.Damage);
    battleInterface(g_Console);
    renderPlayerStats(g_Console, plr);
    renderEnemyStats(g_Console, enemy);
}