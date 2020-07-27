#pragma once

#include <vector>
#include "EditorMap.h"
#include "../content/UIObjects.h"

class EditorTile : public EditorMap
{
public:
	EditorTile();

	void setTile(int position, char type);
	void setOther(int position, char type);
	
	char chosenTile = 0;

	UIobj::Texture TCPU, Tspawner;

	std::vector<sf::Sprite> vecSpawners;
	sf::Sprite CPU;
};

