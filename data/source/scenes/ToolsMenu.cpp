#include "ToolsMenu.h"

ToolsMenu::ToolsMenu()
{
	shaderChrono.start();
	toolsMenuRenderer.setPosition(1280, 720);
}

void ToolsMenu::draw(sf::RenderWindow& window)
{
	toolsMenuRenderer.render(window);
}

void ToolsMenu::update()
{
	static float shaderTime = 0.0f;
	static bool shaderInverse = false;
	sf::Time time = shaderChrono.getTime();
	if (time.asMilliseconds() >= 15)
	{
		shaderChrono.reset();
		if (shaderTime <= 0.f)
			shaderInverse = false;
		else if (shaderTime >= 1.f)
			shaderInverse = true;
		if (!shaderInverse)
			shaderTime += 0.001f;
		else
			shaderTime -= 0.001f;
		shaderChrono.start();
	}
	toolsMenuRenderer.setWaveShader(shaderTime);
}

void ToolsMenu::mouseMoved(sf::Vector2f MP)
{
	if (toolsMenuRenderer.b1.rectform.getGlobalBounds().contains(MP))
		toolsMenuRenderer.b1.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		toolsMenuRenderer.b1.rectform.setFillColor(sf::Color::Black);

	if (toolsMenuRenderer.b2.rectform.getGlobalBounds().contains(MP))
		toolsMenuRenderer.b2.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		toolsMenuRenderer.b2.rectform.setFillColor(sf::Color::Black);

	if (toolsMenuRenderer.b3.rectform.getGlobalBounds().contains(MP))
		toolsMenuRenderer.b3.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		toolsMenuRenderer.b3.rectform.setFillColor(sf::Color::Black);

	if (toolsMenuRenderer.b4.rectform.getGlobalBounds().contains(MP))
		toolsMenuRenderer.b4.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		toolsMenuRenderer.b4.rectform.setFillColor(sf::Color::Black);

	if (toolsMenuRenderer.b5.rectform.getGlobalBounds().contains(MP))
		toolsMenuRenderer.b5.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		toolsMenuRenderer.b5.rectform.setFillColor(sf::Color::Black);

	if (toolsMenuRenderer.b6.rectform.getGlobalBounds().contains(MP))
		toolsMenuRenderer.b6.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		toolsMenuRenderer.b6.rectform.setFillColor(sf::Color::Black);

	if (toolsMenuRenderer.bexit.rectform.getGlobalBounds().contains(MP))
		toolsMenuRenderer.bexit.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		toolsMenuRenderer.bexit.rectform.setFillColor(sf::Color::Black);
}

void ToolsMenu::click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window)
{
	scene = 0;
	if (toolsMenuRenderer.b1.rectform.getGlobalBounds().contains(MP))
		scene = Scenes::customMenu;
	else if (toolsMenuRenderer.b6.rectform.getGlobalBounds().contains(MP))
		scene = Scenes::editorMenu;
	else if (toolsMenuRenderer.bexit.rectform.getGlobalBounds().contains(MP))
		scene = Scenes::mainMenu;
}