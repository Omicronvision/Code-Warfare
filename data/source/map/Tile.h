#pragma once

#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile();
	Tile(sf::Vector2f texCoord);
	sf::Vector2f texCoords;
};

