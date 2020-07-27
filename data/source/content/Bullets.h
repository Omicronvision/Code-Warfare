#pragma once

#include <SFML/Graphics.hpp>
#include "../entities/bullets/Bullet.h"

class Bullets
{
public:
	Bullets();
	Bullet defenderBullet, sentryBullet, multiBullet;
};

