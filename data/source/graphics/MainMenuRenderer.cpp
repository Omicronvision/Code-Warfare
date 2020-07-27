#include "MainMenuRenderer.h"

MainMenuRenderer::MainMenuRenderer():
tbutton1("Single player",  50, sf::Color::White, sf::Color::Black, 4),
tbutton2("Tools and more", 50, sf::Color::White, sf::Color::Black, 4),
tbutton3("Options",        50, sf::Color::White, sf::Color::Black, 4),
tbutton4("Exit",           50, sf::Color::White, sf::Color::Black, 4),
tinfo("Created by Enchant3d, version 0.0.5", 20, sf::Color::White, sf::Color::Black, 2),
button1(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
button2(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
button3(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
button4(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
TmainTitle("data/graphics/text/main-menu-title.png", false, false),
TmainMenuBack1("data/graphics/other/main-menu-background-1.png", false, false),
TmainMenuBack2("data/graphics/other/main-menu-background-2.png", false, false),
TmainMenuBack3("data/graphics/other/main-menu-background-3.png", false, false),
TmainMenuBack4("data/graphics/other/main-menu-background-4.png", false, false),
TversionTitle("data/graphics/text/version-title.png", false, false)
{
	// setting fonts
	tbutton1.text.setFont(fonts.general);
	tbutton2.text.setFont(fonts.general);
	tbutton3.text.setFont(fonts.general);
	tbutton4.text.setFont(fonts.general);
	tinfo.text.setFont(fonts.general);

	// setting sprites textures
	mainTitle.setTexture(TmainTitle.texture);
	mainMenuBack.setTexture(TmainMenuBack1.texture);
	versionTitle.setTexture(TversionTitle.texture);

	// shader setting
	if (!waveEffect.loadFromFile("data/shaders/wave.vert", "data/shaders/blur.frag"))
		exit(3);
}

MainMenuRenderer::~MainMenuRenderer()
{
	
}

void MainMenuRenderer::setPosition(UInt32 width, UInt32 height)
{
	mainMenuBack.setPosition(sf::Vector2f(0, 0));
	mainTitle.setPosition(sf::Vector2f(width / 2 - TmainTitle.texture.getSize().x / 2, 50));
	versionTitle.setPosition(sf::Vector2f(width / 2 + 235 - TversionTitle.texture.getSize().x / 2, 120));
	button1.rectform.setPosition(sf::Vector2f(sf::Vector2f(width / 2 - button1.rectform.getSize().x / 2, 150)));
	button2.rectform.setPosition(sf::Vector2f(sf::Vector2f(width / 2 - button2.rectform.getSize().x / 2, 250)));
	button3.rectform.setPosition(sf::Vector2f(sf::Vector2f(width / 2 - button3.rectform.getSize().x / 2, 350)));
	button4.rectform.setPosition(sf::Vector2f(sf::Vector2f(width / 2 - button4.rectform.getSize().x / 2, 450)));
	tbutton1.text.setPosition(sf::Vector2f(width / 2 + 40 - button1.rectform.getSize().x / 2, 155));
	tbutton2.text.setPosition(sf::Vector2f(width / 2 + 25 - button1.rectform.getSize().x / 2, 255));
	tbutton3.text.setPosition(sf::Vector2f(width / 2 + 90 - button1.rectform.getSize().x / 2, 355));
	tbutton4.text.setPosition(sf::Vector2f(width / 2 + 120 - button1.rectform.getSize().x / 2, 455));
}

void MainMenuRenderer::setWaveShader(float time)
{
	waveEffect.setUniform("wave_phase", time);
	waveEffect.setUniform("wave_amplitude", sf::Vector2f(0, 0));
	waveEffect.setUniform("blur_radius", time);
}

void MainMenuRenderer::render(sf::RenderWindow &window)
{
	window.draw(mainMenuBack, &waveEffect);
	window.draw(mainTitle);
	window.draw(versionTitle);
	window.draw(button1.rectform);
	window.draw(button2.rectform);
	window.draw(button3.rectform);
	window.draw(button4.rectform);
	window.draw(tbutton1.text);
	window.draw(tbutton2.text);
	window.draw(tbutton3.text);
	window.draw(tbutton4.text);
	window.draw(tinfo.text);
}