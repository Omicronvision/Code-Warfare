#include "MainMenu.h"

MainMenu::MainMenu()
{
	shaderChrono.start();
	textureChrono.start();
	mainMenuRenderer.setPosition(1280, 720);
}

void MainMenu::draw(sf::RenderWindow& window)
{
	mainMenuRenderer.render(window);
}

void MainMenu::update()
{
	static float shaderTime = 0.0f;
	static bool shaderInverse = false;
	sf::Time time = shaderChrono.getTime();
	if(time.asMilliseconds() >= 15)
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
	mainMenuRenderer.setWaveShader(shaderTime);

	if (textureChrono.getTimeAsSeconds() >= 16)
	{
		mainMenuRenderer.mainMenuBack.setTexture(mainMenuRenderer.TmainMenuBack1.texture);
		textureChrono.reset();
		textureChrono.start();
	} else if (textureChrono.getTimeAsSeconds() >= 12)
		mainMenuRenderer.mainMenuBack.setTexture(mainMenuRenderer.TmainMenuBack2.texture);
	else if (textureChrono.getTimeAsSeconds() >= 8)
		mainMenuRenderer.mainMenuBack.setTexture(mainMenuRenderer.TmainMenuBack3.texture);
	else if (textureChrono.getTimeAsSeconds() >= 4)
		mainMenuRenderer.mainMenuBack.setTexture(mainMenuRenderer.TmainMenuBack4.texture);
}

void MainMenu::mouseMoved(sf::Vector2f MP)
{
	if (mainMenuRenderer.button1.rectform.getGlobalBounds().contains(MP))
		mainMenuRenderer.button1.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		mainMenuRenderer.button1.rectform.setFillColor(sf::Color::Black);

	if (mainMenuRenderer.button2.rectform.getGlobalBounds().contains(MP))
		mainMenuRenderer.button2.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		mainMenuRenderer.button2.rectform.setFillColor(sf::Color::Black);

	if (mainMenuRenderer.button3.rectform.getGlobalBounds().contains(MP))
		mainMenuRenderer.button3.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		mainMenuRenderer.button3.rectform.setFillColor(sf::Color::Black);

	if (mainMenuRenderer.button4.rectform.getGlobalBounds().contains(MP))
		mainMenuRenderer.button4.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		mainMenuRenderer.button4.rectform.setFillColor(sf::Color::Black);
}

void MainMenu::click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window)
{
	scene = 0;
	if (mainMenuRenderer.button1.rectform.getGlobalBounds().contains(MP))
		scene = Scenes::soloMenu;
	else if (mainMenuRenderer.button2.rectform.getGlobalBounds().contains(MP))
		scene = Scenes::toolsMenu;
	else if (mainMenuRenderer.button3.rectform.getGlobalBounds().contains(MP))
		scene = Scenes::optionsMenu;
	else if (mainMenuRenderer.button4.rectform.getGlobalBounds().contains(MP))
		window.close();
}