#include "EditorMap.h"

EditorMap::EditorMap()
{}

void EditorMap::resetTileMap()
{
	std::fill(std::begin(tilemap), std::begin(tilemap) + 2500, '.');
	editorTileMap.getMap(tilemap);
	editorTileMap.loadTileMap(50, 50);
}