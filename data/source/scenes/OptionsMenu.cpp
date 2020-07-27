#include "OptionsMenu.h"

OptionsMenu::OptionsMenu()
{
	shaderChrono.start();
	optionsMenuRenderer.setPosition(1280, 720);
	jsonSettings.readSettings();
	variables.changeControls();
}

void OptionsMenu::draw(sf::RenderWindow& window)
{
	optionsMenuRenderer.render(window, variables.music, variables.soundEffects, 
		variables.heavyShaders, variables.fullscreen, variables.keyControls);
}

void OptionsMenu::update()
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
	optionsMenuRenderer.setWaveShader(shaderTime);
}

void OptionsMenu::mouseMoved(sf::Vector2f MP)
{
	if (optionsMenuRenderer.bexit.rectform.getGlobalBounds().contains(MP))
		optionsMenuRenderer.bexit.rectform.setFillColor(sf::Color(115, 22, 17));
	else
		optionsMenuRenderer.bexit.rectform.setFillColor(sf::Color::Black);
}

void OptionsMenu::click(sf::Vector2f MP, Int32& scene, sf::RenderWindow& window)
{
	scene = 0;
	if (optionsMenuRenderer.b1.rectform.getGlobalBounds().contains(MP))
		variables.music = !variables.music;
	else if (optionsMenuRenderer.b2.rectform.getGlobalBounds().contains(MP))
		variables.soundEffects = !variables.soundEffects;
	else if (optionsMenuRenderer.b3.rectform.getGlobalBounds().contains(MP))
		variables.heavyShaders = !variables.heavyShaders;
	else if (optionsMenuRenderer.b4.rectform.getGlobalBounds().contains(MP))
	{
		variables.fullscreen = !variables.fullscreen;
		if (variables.fullscreen)
			window.create(sf::VideoMode(window.getSize().x, window.getSize().y), "Code Warfare", sf::Style::Fullscreen);
		else
			window.create(sf::VideoMode(window.getSize().x, window.getSize().y), "Code Warfare");
	}
	else if (optionsMenuRenderer.cb1.rectform.getGlobalBounds().contains(MP))
	{
		variables.keyControls = LOW;
		variables.changeControls();

	} else if (optionsMenuRenderer.cb2.rectform.getGlobalBounds().contains(MP))
	{
		variables.keyControls = HIGH;
		variables.changeControls();

	} else if (optionsMenuRenderer.cb3.rectform.getGlobalBounds().contains(MP))
	{
		variables.keyControls = TRISTATE;
		variables.changeControls();

	} else if (optionsMenuRenderer.bexit.rectform.getGlobalBounds().contains(MP))
	{
		jsonSettings.writeSettings();
		scene = Scenes::mainMenu;
	}
}