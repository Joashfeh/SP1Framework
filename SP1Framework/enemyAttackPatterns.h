#pragma once

/* Enemy attack Patterns and Abilities

Patterns (Attack AI)
1 | Standard: Attack only.
2 | Chance of attack based on: 

	attack points / total stats points

3 | Chance of crit | Formula same as chance of attack

Abilities (Unique abiities AI can use in battle):
1 | Damage | Crit (Chance of Double damage at certain percentage)
2 | Defence | Block (Chance of Blocking out all damage at certain percentage)
3 | Health | Regen Health (Healing)
4 | Damage | Fire damage (Gives player fire effect that drains fixed amount of health for some turns)
5 | Defence | Rechargeable Shield
6 | Defence/Damage | Deflective Shield
7 | Defence | Dodge chance. Dodge chance = Defence / Total stats points.
*/

class enemyAttackPatterns
{
public:
	//int pattern_selection;
	//int ability_selection;

	enemyAttackPatterns();
	void pattern_selection(int selection); // Runs selection through a switch check of attack patterns
	void ability_selection(int selection); // Same as pattern_selection but for abilities
	~enemyAttackPatterns();
};