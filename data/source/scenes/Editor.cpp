#include "Editor.h"

Editor::Editor()
{
	editorRenderer.setPosition(0, 0, 1280, 720);
	editorTile.resetTileMap();
}

void Editor::draw(sf::RenderWindow& window)
{
	window.draw(editorTile.editorTileMap);
	window.draw(editorTile.CPU);
	for (unsigned int i = 0; i < editorTile.vecSpawners.size(); i++)
		window.draw(editorTile.vecSpawners[i]);
	editorRenderer.render(window);
}

void Editor::update(Int32 x, Int32 y)
{
	editorRenderer.setPosition(x, y, sx, sy);
}

void Editor::mouseMoved(sf::Vector2f MP, sf::Vector2f MPC)
{
	sf::FloatRect b1(sf::Vector2f(5, 645), sf::Vector2f(200, 80));
	sf::FloatRect b2(sf::Vector2f(5, 565), sf::Vector2f(200, 80));
	sf::FloatRect b3(sf::Vector2f(5, 485), sf::Vector2f(200, 80));

	const int tmx = (int)MPC.x / 50 + 1;
	const int tmy = (int)MPC.y / 50 + 1;
	std::stringstream ss;
	ss << "x: " << tmx << "\ny: " << tmy;
	editorRenderer.tpos.text.setString(ss.str());

	if (b1.contains(MP))
		editorRenderer.buttonExit.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		editorRenderer.buttonExit.rectform.setFillColor(sf::Color::Black);

	if (b2.contains(MP))
		editorRenderer.buttonSave.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		editorRenderer.buttonSave.rectform.setFillColor(sf::Color::Black);

	if (b3.contains(MP))
		editorRenderer.buttonLoad.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		editorRenderer.buttonLoad.rectform.setFillColor(sf::Color::Black);
}

void Editor::click(sf::Vector2f MP, sf::Vector2f MPC, Int32& scene, sf::RenderWindow& window)
{
	scene = 0;
	sf::FloatRect b1(sf::Vector2f(5, 645), sf::Vector2f(200, 80));
	sf::FloatRect b2(sf::Vector2f(5, 565), sf::Vector2f(200, 80));
	sf::FloatRect b3(sf::Vector2f(5, 485), sf::Vector2f(200, 80));

	if (b1.contains(MP))
		scene = Scenes::mainMenu;
	else if (b2.contains(MP))
	{
		std::vector<sf::Vector2f> vecSpawnersPos;
		for (unsigned int i = 0; i < editorTile.vecSpawners.size(); i++)
		{
			vecSpawnersPos.push_back(editorTile.vecSpawners[i].getPosition());
		}
		if (mapIO.write("data/maps/electrohalls.dat", std::string(editorTile.tilemap), editorTile.CPU.getPosition(), vecSpawnersPos))
			editorRenderer.tinfo.text.setString("Map saved successfully as \"newMap.data\"");
		else
			editorRenderer.tinfo.text.setString("Map saved unsuccessfully :(");
	}
	else if (b3.contains(MP))
		0;
	else if (sf::FloatRect(5, 5, 200, 250).contains(MP))
	{
		if(showMenu)
		{
			if (sf::FloatRect(5, 5, 50, 50).contains(MP))
				editorTile.chosenTile = 1;
			else if (sf::FloatRect(55, 5, 50, 50).contains(MP))
				editorTile.chosenTile = 2;
			else if (sf::FloatRect(105, 5, 50, 50).contains(MP))
				editorTile.chosenTile = 3;
			else if (sf::FloatRect(155, 5, 50, 50).contains(MP))
				editorTile.chosenTile = 4;
			else if (sf::FloatRect(5, 55, 50, 50).contains(MP))
				editorTile.chosenTile = 5;
			else if (sf::FloatRect(55, 55, 50, 50).contains(MP))
				editorTile.chosenTile = 6;
			else if (sf::FloatRect(105, 55, 50, 50).contains(MP))
				editorTile.chosenTile = 7;
			else if (sf::FloatRect(155, 55, 50, 50).contains(MP))
				editorTile.chosenTile = 8;
			else if (sf::FloatRect(5, 105, 50, 50).contains(MP))
				editorTile.chosenTile = 9;
			else if (sf::FloatRect(55, 105, 50, 50).contains(MP))
				editorTile.chosenTile = 10;
			else if (sf::FloatRect(105, 105, 50, 50).contains(MP))
				editorTile.chosenTile = 11;
			else if (sf::FloatRect(155, 105, 50, 50).contains(MP))
				editorTile.chosenTile = 12;
			else if (sf::FloatRect(5, 155, 50, 50).contains(MP))
				editorTile.chosenTile = 13;
			else if (sf::FloatRect(55, 155, 50, 50).contains(MP))
				editorTile.chosenTile = 14;
			else if (sf::FloatRect(105, 155, 50, 50).contains(MP))
				editorTile.chosenTile = 15;
			else if (sf::FloatRect(155, 155, 50, 50).contains(MP))
				editorTile.chosenTile = 16;
			else if (sf::FloatRect(5, 205, 50, 50).contains(MP))
				editorTile.chosenTile = 17;
			else if (sf::FloatRect(55, 205, 50, 50).contains(MP))
				editorTile.chosenTile = 18;
			else if (sf::FloatRect(105, 205, 50, 50).contains(MP))
				editorTile.chosenTile = 19;
			else if (sf::FloatRect(155, 205, 50, 50).contains(MP))
				editorTile.chosenTile = 20;
		}
		sx = ((editorTile.chosenTile - 1) % 4) * 50;
		sy = ((editorTile.chosenTile - 1) / 4) * 50;

	} else
	{
		const int tmx = (int)MPC.x / 50 + 1;
		const int tmy = (int)MPC.y / 50;
		const int tmpos = tmx + (tmy * 50) - 1;

		if (editorTile.chosenTile <= 16)
			editorTile.setTile(tmpos, editorTile.chosenTile);
		else
			editorTile.setOther(tmpos, editorTile.chosenTile);
	}
}