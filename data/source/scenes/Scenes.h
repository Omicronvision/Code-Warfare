#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "ToolsMenu.h"
#include "OptionsMenu.h"
#include "SoloMenu.h"
#include "Map.h"
#include "Editor.h"

class Scenes
{
public:
	Scenes();
	enum Scene
	{
		mainMenu = 1,
		soloMenu = 2,
		toolsMenu = 3,
		optionsMenu = 5,
		editorMenu = 6,
		customMenu = 7,
		map = 8
	};
	Scene currentScene;
};

