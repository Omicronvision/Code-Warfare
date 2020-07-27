#include "Defensive.h"

Defensive::Defensive(std::string name, Int32 ID):
building(name, ID), damage(0)
{}

Int32 Defensive::getDamage()
{
	return damage;
}

bool Defensive::isEnemy(sf::FloatRect box)
{
	sf::FloatRect defBox(building.quad->position.x, building.quad->position.y, 50, 50);
	if (defBox.intersects(box))
		return true;
	else
		return false;
}