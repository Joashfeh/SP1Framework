#pragma once
#include <string>
#include "Map.h"
using namespace std;

class Enemy
{
public:
	Enemy();
	void setenemystats(Map type); // Sets enemy stats based on type of enemy | Enemy type stored in this function
	~Enemy();
};

