#pragma once

#include <SFML/Graphics.hpp>
#include "../../framework/DataTypes.h"

using namespace dt;

class Bullet
{
public:
	Bullet(std::string filename, Int8 ID);
	void draw(sf::RenderWindow& window);
	void getEnemyPosition(sf::Vector2f enemyPos, sf::Vector2f initPos, Int32 damage);
	bool update();
	bool isEnemyTouched(sf::FloatRect box);

	sf::Sprite bullet;
	Int32 damage;
	float lifeTime;
	float maxSpeed;
	const Int8 ID;

private:
	sf::Texture texture;
	sf::Clock clock;
	sf::Vector2f initPos;
	sf::Vector2f direction;
	sf::Vector2f ndirection;
	sf::Vector2f velocity;
};

