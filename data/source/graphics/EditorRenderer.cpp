#include "EditorRenderer.h"

EditorRenderer::EditorRenderer():
texit("Exit", 50, sf::Color::White, sf::Color::Black, 2),
tsave("Save", 50, sf::Color::White, sf::Color::Black, 2),
tload("Load", 50, sf::Color::White, sf::Color::Black, 2),
tpos("", 30, sf::Color::White, sf::Color::Black, 2),
tinfo("", 50, sf::Color::White, sf::Color::Black, 2),
editingMenu(sf::Color::Black, sf::Color::White, 2, sf::Vector2f(200, 720)),
buttonExit(sf::Color::Black, sf::Color::White, 2, sf::Vector2f(200, 80)),
buttonSave(sf::Color::Black, sf::Color::White, 2, sf::Vector2f(200, 80)),
buttonLoad(sf::Color::Black, sf::Color::White, 2, sf::Vector2f(200, 80)),
selectedTile(sf::Color(0, 0, 255, 80), sf::Vector2f(50, 50)),
Ttiles("data/graphics/tiles/editor-tiles.png", true, false)
{
	/// setting text font
	texit.text.setFont(fonts.general);
	tsave.text.setFont(fonts.general);
	tload.text.setFont(fonts.general);
	tinfo.text.setFont(fonts.general);
	tpos.text.setFont(fonts.general);

	// setting sprite texture
	tiles.setTexture(Ttiles.texture);
}

EditorRenderer::~EditorRenderer()
{

}

void EditorRenderer::setPosition(Int32 x, Int32 y, Int32 sx, Int32 sy)
{
	editingMenu.rectform.setPosition(sf::Vector2f(x + 5, y + 5));
	tiles.setPosition(sf::Vector2f(x + 5, y + 5));
	buttonExit.rectform.setPosition(sf::Vector2f(x + 5, y + 5 + editingMenu.rectform.getSize().y - buttonExit.rectform.getSize().y));
	buttonSave.rectform.setPosition(sf::Vector2f(x + 5, y + 5 + editingMenu.rectform.getSize().y - buttonSave.rectform.getSize().y * 2));
	buttonLoad.rectform.setPosition(sf::Vector2f(x + 5, y + 5 + editingMenu.rectform.getSize().y - buttonLoad.rectform.getSize().y * 3));
	texit.text.setPosition(sf::Vector2f(buttonExit.rectform.getPosition().x + 65, buttonExit.rectform.getPosition().y + 8));
	tsave.text.setPosition(sf::Vector2f(buttonSave.rectform.getPosition().x + 65, buttonSave.rectform.getPosition().y + 8));
	tload.text.setPosition(sf::Vector2f(buttonLoad.rectform.getPosition().x + 65, buttonLoad.rectform.getPosition().y + 8));
	tinfo.text.setPosition(sf::Vector2f(x / 2 - tinfo.text.getLocalBounds().width / 2, 25));
	tpos.text.setPosition(sf::Vector2f(x + 10, y - tpos.text.getLocalBounds().height + 800));
	selectedTile.rectform.setPosition(sf::Vector2f(x + 5 + sx, y + 5 + sy));
}

void EditorRenderer::render(sf::RenderWindow& window)
{
	window.draw(editingMenu.rectform);
	window.draw(tiles);
	window.draw(buttonExit.rectform);
	window.draw(buttonSave.rectform);
	window.draw(buttonLoad.rectform);
	window.draw(selectedTile.rectform);
	window.draw(texit.text);
	window.draw(tsave.text);
	window.draw(tload.text);
	window.draw(tinfo.text);
	window.draw(tpos.text);
}