#include "Bullet.h"

Bullet::Bullet(std::string filename, Int8 ID):
velocity(0.f, 0.f), direction(0.f, 0.f), ndirection(0.f, 0.f), ID(ID), lifeTime(0.f), maxSpeed(0.f),
damage(0)
{
	if (!texture.loadFromFile(filename))
		exit(1);
	texture.setSmooth(true);
	bullet.setTexture(texture);
}

void Bullet::draw(sf::RenderWindow &window)
{
	window.draw(bullet);
}

void Bullet::getEnemyPosition(sf::Vector2f enemyPos, sf::Vector2f initPos, Int32 damage)
{
	this->damage = damage;
	this->initPos = initPos + sf::Vector2f(25, 25);
	direction = enemyPos - initPos;
	bullet.setPosition(initPos);
	clock.restart();
}

bool Bullet::update()
{
	ndirection = direction / sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	velocity = ndirection * maxSpeed;
	bullet.move(velocity);
	if (lifeTime <= clock.getElapsedTime().asSeconds())
		return false;
	else
		return true;
}

bool Bullet::isEnemyTouched(sf::FloatRect box)
{
	sf::FloatRect bulletBox = bullet.getGlobalBounds();
	if (bulletBox.intersects(box))
		return true;
	else
		return false;
}