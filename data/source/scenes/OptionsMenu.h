#pragma once

#include <SFML/Graphics.hpp>
#include "Scenes.h"
#include "../Variables.h"
#include "../framework/DataTypes.h"
#include "../framework/Chrono.h"
#include "../graphics/OptionsMenuRenderer.h"
#include "../io/JsonIO.h"

using namespace dt;

class OptionsMenu
{
public:
	OptionsMenu();
	void draw(sf::RenderWindow& window);
	void update();
	void mouseMoved(sf::Vector2f MP);
	void click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window);
	OptionsMenuRenderer optionsMenuRenderer;

private:
	JsonIO jsonSettings;
	Variables variables;
	Chrono shaderChrono;
};

