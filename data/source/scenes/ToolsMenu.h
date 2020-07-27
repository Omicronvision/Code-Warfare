#pragma once

#include <SFML/Graphics.hpp>
#include "Scenes.h"
#include "../framework/DataTypes.h"
#include "../framework/Chrono.h"
#include "../graphics/ToolsMenuRenderer.h"

using namespace dt;

class ToolsMenu
{
public:
	ToolsMenu();
	void draw(sf::RenderWindow& window);
	void update();
	void mouseMoved(sf::Vector2f MP);
	void click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window);
	ToolsMenuRenderer toolsMenuRenderer;

private:
	Chrono shaderChrono;
};

