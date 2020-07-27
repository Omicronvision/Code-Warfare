#pragma once

#include <SFML/Graphics.hpp>

class Fonts
{
public:
	Fonts();
	~Fonts();
	sf::Font general;        //  font used for big texts
	sf::Font info;           //  font used for descriptions, chat and errors
};

