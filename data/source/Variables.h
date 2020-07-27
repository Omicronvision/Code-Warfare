#pragma once

#include <SFML/Graphics.hpp>
#include "framework/DataTypes.h"

using namespace dt;

class Variables
{
public:
	void changeControls();

	// time for fading
	static const float fadingTime;
	// tile size
	static const int tileSize;
	// view min limit
	static const sf::Vector2f minLimit;
	// view max limit
	static const sf::Vector2f maxLimit;

	/* OPTIONS */
	// fullscreen option
	static bool fullscreen;
	// sound effects
	static bool soundEffects;
	// music
	static bool music;
	// heavy shaders
	static bool heavyShaders;
	// controls
	static tristate keyControls;
	static sf::Keyboard::Key moveUp;
	static sf::Keyboard::Key moveDown;
	static sf::Keyboard::Key moveRight;
	static sf::Keyboard::Key moveLeft;
};