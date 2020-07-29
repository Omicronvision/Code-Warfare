#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include "Scenes.h"
#include "../framework/DataTypes.h"
#include "../framework/Chrono.h"
#include "../graphics/MapRenderer.h"
#include "../map/MapRes.h"

using namespace dt;

class Map
{
public:
	Map();
	void draw(sf::RenderWindow& window);
	void update(Int32 x, Int32 y, Int32 width, Int32 height);
	void mouseMoved(sf::Vector2f MP, sf::Vector2f MPC);
	void click(sf::Vector2f MP, sf::Vector2f MPC, Int32& scene, sf::RenderWindow& window, bool paused);
	MapRenderer mapRenderer;
	MapRes mapRes;

private:
	bool categoryChanged, buildChanged;
	Int8 chosenCategory, chosenBuild;
	bool drawBuildInfo;
};

