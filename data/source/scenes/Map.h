#pragma once

#include <SFML/Graphics.hpp>
#include "Scenes.h"
#include "../framework/DataTypes.h"
#include "../framework/Chrono.h"
#include "../graphics/MapRenderer.h"

using namespace dt;

class Map
{
public:
	Map();
	void draw(sf::RenderWindow& window);
	void update();
	void mouseMoved(sf::Vector2f MP);
	void click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window);
	MapRenderer mapRenderer;

private:
	Int8 chosenCategory, chosenBuild;
	bool drawBuildInfo;
};

