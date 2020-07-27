#include "Turret.h"

Turret::Turret(std::string name, Int32 ID)
: building(name, ID), damage(0), shootingTime(0.0f)
{
	radius.setFillColor(sf::Color(255, 255, 0, 35));
	radius.setOrigin(radius.getRadius(), radius.getRadius());
}

void Turret::resetClock()
{
	clock.restart();
}

void Turret::setRadiusPosition()
{
	radius.setPosition(building.quad->position.x + 25, building.quad->position.y + 25);
}

void Turret::drawRadius(sf::RenderWindow &window)
{
	window.draw(radius);
}

Int32 Turret::getDamage()
{
	return damage;
}

bool Turret::isEnemy(sf::FloatRect box)
{
	if ((containsCircle(sf::Vector2f(box.left, box.top))) ||
		(containsCircle(sf::Vector2f(box.left + box.width, box.top))) ||
		(containsCircle(sf::Vector2f(box.left, box.top + box.height))) ||
		(containsCircle(sf::Vector2f(box.left + box.width, box.top + box.height))))
		return true;
	else
		return false;
}

bool Turret::containsCircle(sf::Vector2f vec)
{
	sf::Vector2f center = radius.getPosition();
	float a = (vec.x - center.x);
	float b = (vec.y - center.y);
	a *= a;
	b *= b;
	float r = radius.getRadius() * radius.getRadius();
	return ((a + b) < r);
}

bool Turret::isTime()
{
	if (shootingTime <= clock.getElapsedTime().asSeconds())
		return true;
	else
		return false;
}