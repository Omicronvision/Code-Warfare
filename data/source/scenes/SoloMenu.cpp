#include "SoloMenu.h"

SoloMenu::SoloMenu()
{
	soloMenuRenderer.setPosition(1280, 720);
}

void SoloMenu::draw(sf::RenderWindow& window)
{
	soloMenuRenderer.render(window);
}

void SoloMenu::update()
{
	
}

void SoloMenu::mouseMoved(sf::Vector2f MP)
{
	if (soloMenuRenderer.b1.rectform.getGlobalBounds().contains(MP))
		soloMenuRenderer.b1.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		soloMenuRenderer.b1.rectform.setFillColor(sf::Color::Black);

	if (soloMenuRenderer.b2.rectform.getGlobalBounds().contains(MP))
		soloMenuRenderer.b2.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		soloMenuRenderer.b2.rectform.setFillColor(sf::Color::Black);

	if (soloMenuRenderer.b3.rectform.getGlobalBounds().contains(MP))
		soloMenuRenderer.b3.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		soloMenuRenderer.b3.rectform.setFillColor(sf::Color::Black);

	if (soloMenuRenderer.bE.rectform.getGlobalBounds().contains(MP))
		soloMenuRenderer.bE.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		soloMenuRenderer.bE.rectform.setFillColor(sf::Color::Black);

	if (soloMenuRenderer.bexit.rectform.getGlobalBounds().contains(MP))
		soloMenuRenderer.bexit.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		soloMenuRenderer.bexit.rectform.setFillColor(sf::Color::Black);
}

void SoloMenu::click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window)
{
	scene = 0;
	if (soloMenuRenderer.bexit.rectform.getGlobalBounds().contains(MP))
		scene = Scenes::mainMenu;
}