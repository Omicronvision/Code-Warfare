#pragma once

#include <SFML/Graphics.hpp>
#include "Tiles.h"
#include "../Variables.h"
#include "../framework/DataTypes.h"

using namespace dt;

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	bool checkTile(int tile, char c);
	void loadTileMap(UInt32 sizeX, UInt32 sizeY);
	void getMap(char* mapData);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	char* charMap;

private:
	const Tiles tiles;
	Variables variables;
	sf::VertexArray tm_vertices;
	sf::Texture tilesTexture;
};