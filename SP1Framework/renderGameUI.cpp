#include "renderGameUI.h"
#include <sstream>

void renderGameUI(Console& g_Console, Player& plr, Map& map) {
	displayBoxes(g_Console, 4, 2, 27, 11);
	std::ostringstream ss;

	ss << "Player Health: " << plr.HP;
	g_Console.writeToBuffer(7, 4, ss.str());

	ss.str("");
	ss << "Gold: " << plr.gold;
	g_Console.writeToBuffer(7, 6, ss.str());

	ss.str("");
	ss << "Skulls: " << plr.skulls;
	g_Console.writeToBuffer(7, 8, ss.str());

	ss.str("");
	ss << "Floor: " << map.floor;
	g_Console.writeToBuffer(7, 10, ss.str());

}
