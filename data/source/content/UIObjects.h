#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../framework/RichText.hpp"
#include "../ui/Fonts.h"

namespace UIobj
{
	class RectForm
	{
	public:
		RectForm(sf::Color fillColor, sf::Color outlineColor, int outlineThickness, sf::Vector2f size);
		RectForm(sf::Color fillColor, sf::Vector2f size);
		sf::RectangleShape rectform;
	};

	class Text
	{
	public:
		Text(std::string str, int fontSize, sf::Color fillColor, sf::Color outlineColor, int outlineThickness);
		sf::Text text;
	};

	class RichText
	{
	public:
		RichText(int fontSize);
		sfe::RichText text;
	};

	class Texture
	{
	public:
		Texture(std::string filename, bool smooth, bool repeated);
		sf::Texture texture;
	};
}

extern Fonts fonts;