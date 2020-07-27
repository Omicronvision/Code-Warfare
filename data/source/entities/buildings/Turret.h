#pragma once

#include <SFML/Graphics.hpp>
#include "Building.h"
#include "../../framework/DataTypes.h"

class Turret
{
public:
	Turret(std::string name, Int32 ID);
	void resetClock();                                //  reset clock
	void setRadiusPosition();                         //  set the position of the radius
	void drawRadius(sf::RenderWindow &window);        //  draw radius
	Int32 getDamage();                                //  get turret damage
	bool isTime();                                    //  check if turret can shoot
	bool isEnemy(sf::FloatRect box);                  //  check if enemy is in the turret radius

	Building building;
	float shootingTime;
	Int32 damage;
	sf::CircleShape radius;

private:
	bool containsCircle(sf::Vector2f vec);
	sf::Clock clock;
};

