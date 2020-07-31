#pragma once

#include "../entities/animations/AnimationSprite.h"

class Animations
{
public:
	Animations();
	sf::Texture texEnemyExplosion, texDefExplosion;
	Animation wadEnemyExplosion, wadDefExplosion;
	AnimationSprite animEnemyExplosion, animDefExplosion;
};

