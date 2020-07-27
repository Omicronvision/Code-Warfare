#pragma once

#include <SFML/Graphics.hpp>
#include "../framework/DataTypes.h"
#include "../content/UIObjects.h"

using namespace dt;

class OptionsMenuRenderer
{
public:
	OptionsMenuRenderer();
	~OptionsMenuRenderer();
	void setPosition(UInt32 width, UInt32 height);
	void render(sf::RenderWindow& window, bool music, bool se, bool shaders, bool fullscreen, tristate keys);
	void setWaveShader(float time);

	// User interface objects
	UIobj::Texture ToptionsTitle, Tcheck, ToptionsMenuBack;
	UIobj::RectForm b1, b2, b3, b4, cb1, cb2, cb3, bexit;
	UIobj::Text tmusic, tse, tshaders, tfullscreen, c1, c2, c3, texit;
	sf::Sprite optionsTitle, check, optionsMenuBack;
	sf::Shader waveEffect;
};

