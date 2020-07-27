#pragma once

#include <SFML/Graphics.hpp>
#include "../Variables.h"

class View
{
public:
	View();

	void resetView(sf::RenderWindow& window, sf::Event &event);
	void moveView();
	void zoomView(sf::Vector2i pixel, sf::RenderWindow& window, float zoom);

	sf::CircleShape crosshair;
	sf::View view;
	Variables variables;
};

