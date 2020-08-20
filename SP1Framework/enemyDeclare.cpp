#include "enemyDeclare.h"

void enemyDeclare(Map& map, Enemy* enemies[])
{
    for (int a = 0; a < 3; a++)
    {
<<<<<<< HEAD
        enemies[a]->setenemystats(a);
    }
}

Enemy* get_ptr(int enemy, Enemy* enemies[])
{
    return enemies[enemy];
=======
        entity_ptrs[a]->setenemystats(a);
    }
}

Enemy* get_ptr(int enemy)
{
    return entity_ptrs[enemy];
>>>>>>> 9e4a5a817d8b9f1834c2a23830a360628e3f4f25
}

/*void loadEnemy()
{
}*/