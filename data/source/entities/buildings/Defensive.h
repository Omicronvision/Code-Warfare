#pragma once

#include <SFML/Graphics.hpp>
#include "Building.h"
#include "../../framework/DataTypes.h"

using namespace dt;

class Defensive
{
public:
	Defensive(std::string name, Int32);
	Int32 getDamage();
	bool isEnemy(sf::FloatRect box);

	Building building;
	Int32 damage;
};

