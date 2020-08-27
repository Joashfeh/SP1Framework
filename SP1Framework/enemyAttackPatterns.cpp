#include "enemyAttackPatterns.h"

enemyAttackPatterns::enemyAttackPatterns()
{
	// NULL
}

void enemyAttackPatterns::pattern_selection(int selection)
{
	switch (selection)
	{
	//attack 0 | Does not attack | Usually not called
	case 0:
		// Does nothing | 0 Damage
		break;

	//attack 1 | Attack only
	case 1:
		break;
	//attack 2
	case 2:
		break;
	//attack 3
	case 3:
		break;
	default:
		// Default should not be called as selection is predetermined when enemies are loaded.
		break;
	}
}

void enemyAttackPatterns::ability_selection(int selection)
{
	switch (selection)
	{
	case 0:
		// No abilities
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;

	}
}

enemyAttackPatterns::~enemyAttackPatterns()
{
}
