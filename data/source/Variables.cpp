#include "Variables.h"

void Variables::changeControls()
{
	switch(keyControls)
	{
	case tristate::LOW:
		moveUp = sf::Keyboard::W;
		moveDown = sf::Keyboard::S;
		moveRight = sf::Keyboard::D;
		moveLeft = sf::Keyboard::A;
		break;
	case tristate::HIGH:
		moveUp = sf::Keyboard::Z;
		moveDown = sf::Keyboard::S;
		moveRight = sf::Keyboard::D;
		moveLeft = sf::Keyboard::Q;
		break;
	case tristate::TRISTATE:
		moveUp = sf::Keyboard::Up;
		moveDown = sf::Keyboard::Down;
		moveRight = sf::Keyboard::Right;
		moveLeft = sf::Keyboard::Left;
		break;
	}
}

const float Variables::fadingTime = 0.025f;
const int Variables::tileSize = 50;
const sf::Vector2f Variables::minLimit = sf::Vector2f(0, 0);
const sf::Vector2f Variables::maxLimit = sf::Vector2f(2500, 2500);

bool Variables::fullscreen   = false;
bool Variables::soundEffects = true;
bool Variables::music        = true;
bool Variables::heavyShaders = true;

tristate Variables::keyControls    = tristate::LOW;
sf::Keyboard::Key Variables::moveUp    = sf::Keyboard::W;
sf::Keyboard::Key Variables::moveDown  = sf::Keyboard::S;
sf::Keyboard::Key Variables::moveRight = sf::Keyboard::D;
sf::Keyboard::Key Variables::moveLeft  = sf::Keyboard::A;