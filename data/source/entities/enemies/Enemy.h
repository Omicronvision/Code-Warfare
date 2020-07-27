#pragma once

#include <SFML/Graphics.hpp>
#include "../../framework/DataTypes.h"

using namespace dt;

class Enemy
{
public:
	Enemy(std::string filename, Int8 ID);
	virtual ~Enemy();
	void moveEnemy();
	void changeDirection(Int8 direction);
	void initPosition(sf::Vector2f position);
	void setTarget(Int32 target);
	void setHealth(Int32 health);
	void setSpeed(Int32 speed);
	void draw(sf::RenderWindow& window);
	Int32 getTarget();
	Int32 getPath();
	Int32 getHealth();
	Int32 getTile();
	sf::Vector2f getPosition();
	sf::FloatRect getBox();

	float speed;                                        //  enemy's speed
	float initialSpeed;                                 //  initial enemy speed
	const Int8 ID;										//  enemy's ID
	Int32 health;										//  enemy's health
	Int8 ttdamage;
	bool visible;

private:
	Int32 target;										//  the position where the enemy need to go
	Int32 path;											//  enemy's path
	Int8 direction;										//  enemy's direction (1, 2, 3, 4)
	enum{UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4};
	sf::Texture texture;
	sf::Sprite sprite;
};

