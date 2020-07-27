#include "UIObjects.h"

Fonts fonts;

UIobj::RectForm::RectForm(sf::Color fillColor, sf::Color outlineColor, int outlineThickness, sf::Vector2f size)
{
	rectform.setFillColor(fillColor);
	rectform.setOutlineColor(outlineColor);
	rectform.setOutlineThickness(static_cast<float>(outlineThickness));
	rectform.setSize(size);
}

UIobj::RectForm::RectForm(sf::Color fillColor, sf::Vector2f size)
{
	rectform.setFillColor(fillColor);
	rectform.setSize(size);
}

UIobj::Text::Text(std::string str, int fontSize, sf::Color fillColor, sf::Color outlineColor, int outlineThickness)
{
	text.setString(str);
	text.setCharacterSize(fontSize);
	text.setFillColor(fillColor);
	text.setOutlineColor(outlineColor);
	text.setOutlineThickness(static_cast<float>(outlineThickness));
}

UIobj::RichText::RichText(int fontSize)
{
	text.setCharacterSize(fontSize);
}

UIobj::Texture::Texture(std::string filename, bool smooth, bool repeated)
{
	if (!texture.loadFromFile(filename))
		exit(2);
	texture.setSmooth(smooth);
	texture.setRepeated(repeated);
}