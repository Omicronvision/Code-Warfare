#pragma once

#include <SFML/Graphics.hpp>
#include "Building.h"
#include "../../framework/DataTypes.h"

using namespace dt;

class Productive
{
public:
	Productive(std::string name, Int32 ID);
	void resetClock();
	Int32 getTimeGreenCoin();
	Int32 getTimeElectroPiece();

	Building building;                      //  building
	float productionTime;                   //  time needed for every production
	Int32 prodGC;                           //  green coin production value
	Int32 prodEP;                           //  electro piece production value

private:
	sf::Clock clock;
};

