#include "Building.h"

Building::Building(std::string name, Int32 ID):
priceGC(0), priceEP(0), name(name), ID(ID), texturePos(sf::Vector2f(0, 0)), CPU_usage(0)
{}

void Building::setPosition(Int32 tile)
{
	const Int32 x = tile % 50;
	const Int32 y = tile / 50;
	quad[0].position = sf::Vector2f(x * 50, y * 50);
	quad[1].position = sf::Vector2f(x * 50 + 50, y * 50);
	quad[2].position = sf::Vector2f(x * 50 + 50, y * 50 + 50);
	quad[3].position = sf::Vector2f(x * 50, y * 50 + 50);
}

void Building::setTexture()
{
	quad[0].texCoords = sf::Vector2f(0 + texturePos.x, 0 + texturePos.y);
	quad[1].texCoords = sf::Vector2f(0 + texturePos.x + 50, 0 + texturePos.y);
	quad[2].texCoords = sf::Vector2f(0 + texturePos.x + 50, 0 + texturePos.y + 50);
	quad[3].texCoords = sf::Vector2f(0 + texturePos.x, 0 + texturePos.y + 50);
}

Int32 Building::getPriceGC()
{
	return priceGC;
}

Int32 Building::getPriceEP()
{
	return priceEP;
}

Int32 Building::getCPU_usage()
{
	return CPU_usage;
}

std::string Building::getName()
{
	return name;
}