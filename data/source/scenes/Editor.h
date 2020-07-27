#pragma once

#include <SFML/Graphics.hpp>
#include "Scenes.h"
#include "../framework/DataTypes.h"
#include "../framework/Chrono.h"
#include "../graphics/EditorRenderer.h"
#include "../editor/EditorTile.h"
#include "../io/MapIO.h"

using namespace dt;

class Editor
{
public:
	Editor();
	void draw(sf::RenderWindow& window);
	void update(Int32 x, Int32 y);
	void mouseMoved(sf::Vector2f MP, sf::Vector2f MPC);
	void click(sf::Vector2f MP, sf::Vector2f MPC, Int32& scene, sf::RenderWindow& window);

	EditorRenderer editorRenderer;

private:
	MapIO mapIO;
	EditorTile editorTile;

	UInt32 sx = -1000;
	UInt32 sy = -1000;
	bool showMenu = true;
};

