#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
	Animation();
	void addFrame(sf::IntRect rect);
	void setSpriteSheet(const sf::Texture& tex);
	const sf::Texture* getSpriteSheet() const;
	std::size_t getSize() const;
	const sf::IntRect& getFrame(std::size_t n) const;

private:
	std::vector<sf::IntRect> frames;
	const sf::Texture* texture;
};