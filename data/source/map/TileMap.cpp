#include "TileMap.h"

TileMap::TileMap()
{
	if (!tilesTexture.loadFromFile("data/graphics/tiles/tiles-1.png"))
		exit(4);
	tilesTexture.setSmooth(true);
}

void TileMap::getMap(char* mapData)
{
	charMap = mapData;
}

bool TileMap::checkTile(int tile, char c)
{
	if (charMap[tile] == c)
		return true;
	else
		return false;
}

void TileMap::loadTileMap(UInt32 sizeX, UInt32 sizeY)
{
	tm_vertices.clear();
	tm_vertices.setPrimitiveType(sf::Quads);
	tm_vertices.resize(sizeX * sizeY * 4);

	UInt32 index = 0;

	for(UInt32 i = 0; i < sizeY; ++i)
		for(UInt32 j = 0; j < sizeX; ++j)
		{
			sf::Vertex* quad = &tm_vertices[(i + j * sizeY) * 4];

			// setting tile position
			UInt32 ts = variables.tileSize;
			quad[0].position = sf::Vector2f(j * ts, i * ts);
			quad[1].position = sf::Vector2f(j * ts + ts, i * ts);
			quad[2].position = sf::Vector2f(j * ts + ts, i * ts + ts);
			quad[3].position = sf::Vector2f(j * ts, i * ts + ts);

			// setting texture position
			sf::Vector2f tex;
			switch(charMap[index])
			{
			case '.':
				tex = tiles.whiteBlank.texCoords; break;
			case '+':
				tex = tiles.redBlank.texCoords; break;
			case '-':
				tex = tiles.blueBlank.texCoords; break;
			case '/':
				tex = tiles.yellowBlank.texCoords; break;
			case 'a':
				tex = tiles.blueWall.texCoords; break;
			case 'c':
				tex = tiles.yellowWall.texCoords; break;
			case 'd':
				tex = tiles.greenWall.texCoords; break;
			case 'e':
				tex = tiles.redWall.texCoords; break;
			case '1':
				tex = tiles.blueLamp.texCoords; break;
			case '2':
				tex = tiles.redLamp.texCoords; break;
			case '3':
				tex = tiles.yellowLamp.texCoords; break;
			case '4':
				tex = tiles.greenLamp.texCoords; break;
			case 'b':
				tex = tiles.stake.texCoords; break;
			case 'h':
				tex = tiles.cryptoBlank.texCoords; break;
			case 'x':
				tex = tiles.blank0.texCoords; break;
			case 'y':
				tex = tiles.blank1.texCoords; break;
			}

			quad[0].texCoords = sf::Vector2f(tex.x, tex.y);
			quad[1].texCoords = sf::Vector2f(tex.x + ts, tex.y);
			quad[2].texCoords = sf::Vector2f(tex.x + ts, tex.y + ts);
			quad[3].texCoords = sf::Vector2f(tex.x, tex.y + ts);

			index++;
		}
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &tilesTexture;
	target.draw(tm_vertices, states);
}