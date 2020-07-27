#pragma once

#include <SFML/Graphics.hpp>
#include "../framework/DataTypes.h"

using namespace dt;

class Fader
{
public:
	Fader();
	void fadeIn(sf::Time time);
	void fadeOut(sf::Time time);
	void draw(sf::RenderWindow& window);
	UInt8 getOpacity();
	sf::RectangleShape transitionForm;

private:
	UInt8 Topacity = 0;
};

