#include "Animations.h"

Animations::Animations():
animEnemyExplosion(sf::seconds(0.2f), true, false, 1),
animDefExplosion(sf::seconds(0.3f), true, false, 2)
{
    ///loading spritesheets
    if (!texEnemyExplosion.loadFromFile("data/graphics/entities/spritesheets/enemy-destruction.png")) exit(1);
    if (!texDefExplosion.loadFromFile("data/graphics/entities/spritesheets/building-destruction.png")) exit(1);
    wadEnemyExplosion.setSpriteSheet(texEnemyExplosion);
    wadDefExplosion.setSpriteSheet(texDefExplosion);
    ///adding frames to animation
    for (int i = 0; i < 14; i++)
        wadEnemyExplosion.addFrame(sf::IntRect(i * 96, 0, 96, 96));
    for (int i = 0; i < 16; i++)
        wadDefExplosion.addFrame(sf::IntRect(i * 128, 0, 128, 128));
}