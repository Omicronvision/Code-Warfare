#pragma once

#include <SFML/Graphics.hpp>
#include "framework/DataTypes.h"
#include "framework/FPSClock.h"
#include "scenes/Scenes.h"
#include "ui/View.h"
#include "ui/Fader.h"

class Game
{
public:
	Game();						  //  constructor
	void run();                   //  principal run function
	void render();                //  render game content
	void update();                //  update game content
	sf::RenderWindow window;      //  game window

private:
	void processEvents();         //  process game events
	void transitionOn();          //  start the fading transition
	void transitionOff();         //  end the fading transition
	bool b_paused;                //  paused game boolean
	Scenes scenes;
	MainMenu mainMenuScene;
	ToolsMenu toolsMenuScene;
	OptionsMenu optionsMenuScene;
	SoloMenu soloMenuScene;
	Map mapScene;
	Editor editorScene;
	Fader fader;
	View view;
	Chrono fadingChrono;
	FPSClock fpsclock;
};