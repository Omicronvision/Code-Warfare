#include "Productive.h"

Productive::Productive(std::string name, Int32 ID) :
building(name, ID), prodGC(0), prodEP(0), productionTime(0.0f)
{}

void Productive::resetClock()
{
	clock.restart();
}

Int32 Productive::getTimeGreenCoin()
{
	if (productionTime <= clock.getElapsedTime().asSeconds())
		return prodGC;
	else
		return 0;
}

Int32 Productive::getTimeElectroPiece()
{
	if (productionTime <= clock.getElapsedTime().asSeconds())
		return prodEP;
	else
		return 0;
}