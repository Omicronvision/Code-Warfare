#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include "Scenes.h"
#include "../framework/DataTypes.h"
#include "../framework/Chrono.h"
#include "../graphics/MapRenderer.h"
#include "../map/MapRes.h"
#include "../io/MapIO.h"
#include "../audio/SoundEffects.h"

using namespace dt;

class Map
{
public:
	Map();
	void loadTileMap(std::string filename);
	void draw(sf::RenderWindow& window, bool paused);
	void update(Int32 x, Int32 y, Int32 width, Int32 height);
	void mouseMoved(sf::Vector2f MP, sf::Vector2f MPC, bool paused, Int32 width, Int32 height);
	void click(sf::Vector2f MP, sf::Vector2f MPC, Int32& scene, sf::RenderWindow& window, bool& paused);
	void updateCoins();
	void updateWaveTime();
	void updateBuildingInfo(std::string name, int CPU_usage, int id, int damage, int range, float shootingSpeed, int gre, int ele);
	MapRenderer mapRenderer;
	MapRes mapRes;

private:
	MapIO mapIO;
	Int8 chosenCategory, chosenBuild;
	bool drawBuildInfo;
};

