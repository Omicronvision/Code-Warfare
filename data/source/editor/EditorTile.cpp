#include "EditorTile.h"

EditorTile::EditorTile():
TCPU("data/graphics/entities/CPU.png", true, false),
Tspawner("data/graphics/entities/internet.png", true, false)
{
	CPU.setTexture(TCPU.texture);
}

void EditorTile::setTile(int position, char type)
{
	char tile = '.';

	switch(type)
	{
	case 1:
		tile = 'a'; break;
	case 2:
		tile = 'e'; break;
	case 3:
		tile = 'c'; break;
	case 4:
		tile = 'd'; break;
	case 5:
		tile = '1'; break;
	case 6:
		tile = '2'; break;
	case 7:
		tile = '3'; break;
	case 8:
		tile = '4'; break;
	case 9:
		tile = '.'; break;
	case 10:
		tile = '+'; break;
	case 11:
		tile = '-'; break;
	case 12:
		tile = '/'; break;
	case 13:
		tile = 'b'; break;
	case 14:
		tile = 'h'; break;
	case 15:
		tile = 'x'; break;
	case 16:
		tile = 'y'; break;
	}

	editorTileMap.charMap[position] = tile;
	editorTileMap.getMap(tilemap);
	editorTileMap.loadTileMap(50, 50);
}

void EditorTile::setOther(int position, char type)
{
	sf::Sprite sprite;
	int x = position % 50;
	int y = position / 50;

	switch(type)
	{
	case 17: // spawner
		sprite.setTexture(Tspawner.texture);
		sprite.setPosition(sf::Vector2f(x * 50, y * 50));
		vecSpawners.push_back(sprite);
		break;
	case 18: // CPU
		CPU.setPosition(sf::Vector2f(x * 50, y * 50));
		break;
	}
}