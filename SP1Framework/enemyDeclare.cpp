#include "enemyDeclare.h"

void enemyDeclare(Map& map)
{
    for (int a = 0; a < 3; a++)
    {
        entity_ptrs[a]->setenemystats(a);
    }
}

Enemy* get_ptr(int enemy)
{
    return entity_ptrs[enemy];
}

/*void loadEnemy()
{
}*/
