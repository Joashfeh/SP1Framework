#pragma once
#include <string>
#include "Map.h"
#include "Entity.h"
using namespace std;

class Enemy : public Entity
{
public:
	Enemy();
	void setenemystats(Map type); // Sets enemy stats based on type of enemy | Enemy type stored in this function
	~Enemy();
};

