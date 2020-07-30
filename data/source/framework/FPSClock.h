#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "../content/UIObjects.h"

class FPSClock
{
public:
	FPSClock();
	void setPosition(int x, int y);
	void update();
	void draw(sf::RenderWindow& window);
	const unsigned int getFPS() const;

private:
	UIobj::Text FPStext;

	uint32_t frame;
	uint32_t FPS;
	sf::Clock clock;
};

