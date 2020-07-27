#include "Map.h"

Map::Map():
chosenCategory(1), chosenBuild(0), drawBuildInfo(false)
{
	mapRenderer.setPosition(1280, 720, 0, 0);
}

void Map::draw(sf::RenderWindow& window)
{
	mapRenderer.render(window, chosenCategory, chosenBuild, drawBuildInfo);
}

void Map::update()
{

}

void Map::mouseMoved(sf::Vector2f MP)
{

}

void Map::click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window)
{

}