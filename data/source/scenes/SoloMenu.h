#pragma once

#include <SFML/Graphics.hpp>
#include "Scenes.h"
#include "../framework/DataTypes.h"
#include "../framework/Chrono.h"
#include "../graphics/soloMenuRenderer.h"
#include "../game/EnabledWaves.h"

using namespace dt;

class SoloMenu
{
public:
	SoloMenu();
	void draw(sf::RenderWindow& window);
	void update();
	void mouseMoved(sf::Vector2f MP);
	void click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window, std::string& mapFileName, bool& newMap);
	SoloMenuRenderer soloMenuRenderer;
	EnabledWaves enabledWaves;
};

