#include "Enemy.h"

Enemy::Enemy(std::string filename, Int8 ID):
initialSpeed(0), speed(0), health(0), visible(true), ID(ID), target(0), direction(UP),
path(0), ttdamage(0)
{
	texture.loadFromFile(filename);
	texture.setSmooth(true);
	sprite.setTexture(texture);
}

Enemy::~Enemy()
{}

void Enemy::moveEnemy()
{
	switch(direction)
	{
	case UP:
		sprite.move(0, -speed);
		break;
	case DOWN:
		sprite.move(0, speed);
		break;
	case LEFT:
		sprite.move(-speed, 0);
		break;
	case RIGHT:
		sprite.move(speed, 0);
		break;
	}
}

void Enemy::changeDirection(Int8 direction)
{
	this->direction = direction;
}

void Enemy::initPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Enemy::setTarget(Int32 target)
{
	this->target = target;
}

void Enemy::setHealth(Int32 health)
{
	this->health = health;
}

void Enemy::setSpeed(Int32 speed)
{
	this->speed = speed;
	this->initialSpeed = speed;
}

void Enemy::draw(sf::RenderWindow &window)
{
	if (visible)
		sprite.setColor(sf::Color(255, 255, 255, 255));
	else
		sprite.setColor(sf::Color(255, 255, 255, 120));

	if(ttdamage != 0)
	{
		sprite.setColor(sf::Color(255, 0, 0, 255));
		ttdamage--;
	}
	window.draw(sprite);
}

Int32 Enemy::getTarget()
{
	return target;
}

Int32 Enemy::getPath()
{
	return path;
}

Int32 Enemy::getHealth()
{
	return health;
}

Int32 Enemy::getTile()
{
	Int32 x = (Int32)sprite.getPosition().x / 50 + 1;
	Int32 y = (Int32)sprite.getPosition().y / 50;
	return x + (y * 50);
}

sf::Vector2f Enemy::getPosition()
{
	return sprite.getPosition();
}

sf::FloatRect Enemy::getBox()
{
	return sprite.getGlobalBounds();
}