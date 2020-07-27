#pragma once

#include <SFML/Graphics.hpp>
#include "../framework/DataTypes.h"
#include "../content/UIObjects.h"

using namespace dt;

class EditorRenderer
{
public:
	EditorRenderer();
	~EditorRenderer();

	void setPosition(Int32 x, Int32 y, Int32 sx, Int32 sy);
	void render(sf::RenderWindow& window);

	// User interface objects
	UIobj::Texture Ttiles;
	UIobj::RectForm buttonExit, buttonSave, buttonLoad, editingMenu, selectedTile;
	UIobj::Text texit, tsave, tload, tpos, tinfo;
	sf::Sprite tiles;
};

