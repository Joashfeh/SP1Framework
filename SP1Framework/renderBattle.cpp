#include "renderBattle.h"

void renderBattle(double& dt, Console& g_Console, Player& plr, Enemy& enemy, int level_here) {
    renderCharacterSprite(g_Console, 5, 15, plr, dt);
    renderCharacterDamage(g_Console, plr, enemy.Damage);
    if ((enemy.enemy_no == 3) && (level_here == 12))
        renderblob(g_Console, 82, 7, true);
    else
        renderEnemySprite(g_Console, 113, 8, enemy, level_here);
    renderEnemyDamage(g_Console, enemy, plr);
    battleInterface(g_Console);
    renderPlayerStats(g_Console, plr);
    renderEnemyStats(g_Console, enemy);
}