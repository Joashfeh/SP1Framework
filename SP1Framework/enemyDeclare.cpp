#include "enemyDeclare.h"

void enemyDeclare(Map& map, Enemy* enemies[])
{
    for (int a = 0; a < 3; a++)
    {
        enemies[a]->setenemystats(a);
    }
}

Enemy* get_ptr(int enemy, Enemy* enemies[])
{
    return enemies[enemy];
    //entity_ptrs[a]->setenemystats(a);
}

/*void loadEnemy()
{
}*/