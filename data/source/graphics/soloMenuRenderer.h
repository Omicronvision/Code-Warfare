#pragma once

#include <SFML/Graphics.hpp>
#include "../framework/DataTypes.h"
#include "../content/UIObjects.h"

using namespace dt;

class SoloMenuRenderer
{
public:
	SoloMenuRenderer();
	~SoloMenuRenderer();
	void setPosition(UInt32 width, UInt32 height);
	void render(sf::RenderWindow& window);

	// User interface objects
	UIobj::Texture TsoloPlayerTitle, Tdif1, Tdif2, Tdif3, Tcube;
	UIobj::RectForm b1, b2, b3, bE, bexit;
	UIobj::Text t1, t2, t3, tE, texit;
	sf::Sprite soloPlayerTitle, dif1, dif2, dif3;
};

