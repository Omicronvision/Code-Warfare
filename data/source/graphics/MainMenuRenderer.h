#pragma once

#include <SFML/Graphics.hpp>
#include "../framework/DataTypes.h"
#include "../content/UIObjects.h"

using namespace dt;

class MainMenuRenderer
{
public:
	MainMenuRenderer();
	~MainMenuRenderer();
	void setPosition(UInt32 width, UInt32 height);
	void render(sf::RenderWindow &window);
	void setWaveShader(float time);
	
	// User interface objects
	UIobj::Texture TmainTitle, TmainMenuBack1, TmainMenuBack2, TmainMenuBack3, TmainMenuBack4, TversionTitle;
	UIobj::RectForm button1, button2, button3, button4;
	UIobj::Text tbutton1, tbutton2, tbutton3, tbutton4, tinfo;
	sf::Sprite mainTitle, mainMenuBack, versionTitle;
	sf::Shader waveEffect;
};

