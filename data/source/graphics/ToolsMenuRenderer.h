#pragma once

#include <SFML/Graphics.hpp>
#include "../framework/DataTypes.h"
#include "../content/UIObjects.h"

using namespace dt;

class ToolsMenuRenderer
{
public:
	ToolsMenuRenderer();
	~ToolsMenuRenderer();
	void setPosition(UInt32 width, UInt32 height);
	void render(sf::RenderWindow& window);
	void setWaveShader(float time);

	// User interface objects
	UIobj::Texture TtoolsTitle, TtoolsMenuBack;
	UIobj::RectForm b1, b2, b3, b4, b5, b6, bexit;
	UIobj::Text t1, t2, t3, t4, t5, t6, texit;
	sf::Sprite toolsTitle, toolsMenuBack;
	sf::Shader waveEffect;
};

