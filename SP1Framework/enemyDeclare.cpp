#include "enemyDeclare.h"

void enemyDeclare(Map& map)
{
    for (int a = 0; a < 12; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            entity_ptrs[b]->setenemystats(map.floor, a);
        }
    }
}
