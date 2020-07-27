#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include "../map/TileMap.h"

class EditorMap
{
public:
	EditorMap();

	void resetTileMap();

	TileMap editorTileMap;
	char tilemap[2500];
};

