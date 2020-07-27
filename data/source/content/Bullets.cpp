#include "Bullets.h"

Bullets::Bullets():
defenderBullet("data/graphics/entities/projectiles/pro1.png", 1),
sentryBullet("data/graphics/entities/projectiles/pro2.png", 2),
multiBullet("data/graphics/entities/projectiles/pro1.png", 3)
{
	// Defender bullet
	defenderBullet.maxSpeed = 4.5f;
	defenderBullet.lifeTime = 2.f;
	
	// Sentry bullet
	sentryBullet.maxSpeed = 6.4f;
	sentryBullet.lifeTime = 2.f;

	// Multi bullet
	multiBullet.maxSpeed = 3.2f;
	multiBullet.lifeTime = 1.f;
}