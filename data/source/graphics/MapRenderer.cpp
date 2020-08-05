#include "MapRenderer.h"

MapRenderer::MapRenderer():
waveInfo("", 30, sf::Color::White, sf::Color::Black, 3),
tpiece1("", 20, sf::Color::White, sf::Color::Black, 1),
tpiece2("", 20, sf::Color::White, sf::Color::Black, 1),
ppiece1("", 20, sf::Color::Red, sf::Color::Black, 1),
ppiece2("", 20, sf::Color::Red, sf::Color::Black, 1),
buildingName("", 25, sf::Color::White, sf::Color::Black, 1),
tpaused("Paused", 60, sf::Color::White, sf::Color::Black, 4),
tm1("Resume", 50, sf::Color::White, sf::Color::Black, 4),
tm2("Quit", 50, sf::Color::White, sf::Color::Black, 4),
tend1("", 70, sf::Color::White, sf::Color::Black, 3),
tend2("", 40, sf::Color::White, sf::Color::Black, 1),
buildMenu(sf::Color::Black, sf::Color::Yellow, 2, sf::Vector2f(200, 300)),
selectedCategory(sf::Color(255, 255, 255, 75), sf::Vector2f(50, 50)),
selectedBuilding(sf::Color(0, 0, 255, 75), sf::Vector2f(50, 50)),
m1(sf::Color::Black, sf::Color::Yellow, 2, sf::Vector2f(300, 80)),
m2(sf::Color::Black, sf::Color::Yellow, 2, sf::Vector2f(300, 80)),
pauseBg(sf::Color(0, 0, 0, 100), sf::Vector2f(2000, 2000)),
infoMenu(sf::Color::Black, sf::Color::Blue, 2, sf::Vector2f(200, 400)),
selectedTile(sf::Color(255, 255, 255, 80), sf::Vector2f(50, 50)),
Tcategory("data/graphics/icons/build-menu-icon.png", true, false),
T1("data/graphics/icons/greencoin.png", true, false),
T2("data/graphics/icons/electronic-piece.png", true, false),
TCPU("data/graphics/entities/CPU.png", true, false),
Tspawner("data/graphics/entities/internet.png", true, false),
Tc1("data/graphics/tiles/c1.png", true, false),
Tc2("data/graphics/tiles/c2.png", true, false),
Tc3("data/graphics/tiles/c3.png", true, false),
Tc4("data/graphics/tiles/c4.png", true, false),
Tbuildings("data/graphics/tiles/tiles-2.png", true, false),
Tbackground("data/graphics/other/game-background.jpg", false, false),
buildingInfo(16)
{
	// setting text font
	waveInfo.text.setFont(fonts.general);
	tpiece1.text.setFont(fonts.general);
	tpiece2.text.setFont(fonts.general);
	ppiece1.text.setFont(fonts.general);
	ppiece2.text.setFont(fonts.general);
	buildingName.text.setFont(fonts.general);
	tpaused.text.setFont(fonts.general);
	tm1.text.setFont(fonts.general);
	tm2.text.setFont(fonts.general);
	tend1.text.setFont(fonts.general);
	tend2.text.setFont(fonts.general);
	buildingInfo.text.setFont(fonts.info);

	// setting sprites textures
	category.setTexture(Tcategory.texture);
	s1.setTexture(T1.texture);
	s2.setTexture(T2.texture);
	CPU.setTexture(TCPU.texture);
	spawner.setTexture(Tspawner.texture);
	c1.setTexture(Tc1.texture);
	c2.setTexture(Tc2.texture);
	c3.setTexture(Tc3.texture);
	c4.setTexture(Tc4.texture);
	background.setTexture(Tbackground.texture);
}

MapRenderer::~MapRenderer()
{

}

void MapRenderer::setPosition(Int32 x, Int32 y, Int32 width, Int32 height)
{
	background.setPosition(x, y);
	buildMenu.rectform.setPosition(sf::Vector2f(x + 10, y + 10));
	category.setPosition(sf::Vector2f(x + 10, y + 10));
	c1.setPosition(sf::Vector2f(x + 10, y + 80));
	c2.setPosition(sf::Vector2f(x + 10, y + 80));
	c3.setPosition(sf::Vector2f(x + 10, y + 80));
	c4.setPosition(sf::Vector2f(x + 10, y + 80));
	waveInfo.text.setPosition(sf::Vector2f(x + 220, y + 5));
	s1.setPosition(sf::Vector2f(x + 12, y + 250));
	s2.setPosition(sf::Vector2f(x + 12, y + 280));
	tpiece1.text.setPosition(sf::Vector2f(x + 45, y + 250));
	tpiece2.text.setPosition(sf::Vector2f(x + 45, y + 280));
	ppiece1.text.setPosition(sf::Vector2f(x + 100, y + 250));
	ppiece2.text.setPosition(sf::Vector2f(x + 100, y + 280));
	buildingName.text.setPosition(sf::Vector2f(x + 12, y + 220));
	m1.rectform.setPosition(sf::Vector2f(x + width / 2 - m1.rectform.getSize().x / 2, y + height / 2 - 200));
	m2.rectform.setPosition(sf::Vector2f(x + width / 2 - m2.rectform.getSize().x / 2, y + height / 2 - 80));
	tm1.text.setPosition(sf::Vector2f(m1.rectform.getPosition().x + 90, m1.rectform.getPosition().y + 5));
	tm2.text.setPosition(sf::Vector2f(m2.rectform.getPosition().x + 115, m2.rectform.getPosition().y + 5));
	tpaused.text.setPosition(sf::Vector2f(x + width / 2 - 70, y + 50));
	pauseBg.rectform.setPosition(sf::Vector2f(x, y));
	infoMenu.rectform.setPosition(sf::Vector2f(x + 10, y + 320));
	buildingInfo.text.setPosition(sf::Vector2f(infoMenu.rectform.getPosition().x + 2, infoMenu.rectform.getPosition().y + 5));
}

void MapRenderer::render(sf::RenderWindow& window, Int8 chosenCategory, Int8 chosenBuild, bool drawBuildInfo, std::vector<sf::Sprite> spawners)
{
	window.draw(selectedTile.rectform);
	window.draw(CPU);
	for (unsigned int i = 0; i < spawners.size(); i++)
	{
		window.draw(spawners[i]);
	}
	window.draw(buildMenu.rectform);
	window.draw(category);
	window.draw(selectedCategory.rectform);

	switch(chosenCategory)
	{
	case 1:
		window.draw(c1); break;
	case 2:
		window.draw(c2); break;
	case 3:
		window.draw(c3); break;
	case 4:
		window.draw(c4); break;
	}

	if (chosenBuild != 0)
		window.draw(selectedBuilding.rectform);
	window.draw(s1);
	window.draw(s2);
	window.draw(tpiece1.text);
	window.draw(tpiece2.text);
	window.draw(waveInfo.text);

	if(drawBuildInfo)
	{
		window.draw(ppiece1.text);
		window.draw(ppiece2.text);
		window.draw(buildingName.text);
		window.draw(infoMenu.rectform);
		window.draw(buildingInfo.text);
	}
}