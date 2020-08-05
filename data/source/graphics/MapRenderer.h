#pragma once

#include <SFML/Graphics.hpp>
#include "../framework/DataTypes.h"
#include "../content/UIObjects.h"

using namespace dt;

class MapRenderer
{
public:
	MapRenderer();
	~MapRenderer();
	void setPosition(Int32 x, Int32 y, Int32 width, Int32 height);
	void render(sf::RenderWindow& window, Int8 chosenCategory, Int8 chosenBuild, bool drawBuildInfo, std::vector<sf::Sprite> spawners);

	// user interface objects
	UIobj::Texture Tcategory, T1, T2, TCPU, Tspawner, Tc1, Tc2, Tc3, Tc4, Tbuildings, Tbackground;
	UIobj::RectForm buildMenu, infoMenu, selectedCategory, selectedBuilding, m1, m2, pauseBg, selectedTile;
	UIobj::Text waveInfo, tpiece1, tpiece2, ppiece1, ppiece2, buildingName, tpaused, tm1, tm2, tend1, tend2;
	UIobj::RichText buildingInfo;
	sf::Sprite category, s1, s2, CPU, spawner, c1, c2, c3, c4, background;
};

