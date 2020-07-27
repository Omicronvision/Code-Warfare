#include "ToolsMenuRenderer.h"

ToolsMenuRenderer::ToolsMenuRenderer():
t1("Custom", 50, sf::Color::White, sf::Color::Black, 4),
t2("Missions", 50, sf::Color::White, sf::Color::Black, 4),
t3("Local", 50, sf::Color::White, sf::Color::Black, 4),
t4("Challenges", 50, sf::Color::White, sf::Color::Black, 4),
t5("Saves", 50, sf::Color::White, sf::Color::Black, 4),
t6("Map editor", 50, sf::Color::White, sf::Color::Black, 4),
texit("Exit", 50, sf::Color::White, sf::Color::Black, 4),
b1(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
b2(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
b3(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
b4(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
b5(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
b6(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 80)),
bexit(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(150, 80)),
TtoolsTitle("data/graphics/text/tools-menu-title.png", false, false),
TtoolsMenuBack("data/graphics/other/tools-menu-background.png", false, false)
{
	// setting font
	t1.text.setFont(fonts.general);
	t2.text.setFont(fonts.general);
	t3.text.setFont(fonts.general);
	t4.text.setFont(fonts.general);
	t5.text.setFont(fonts.general);
	t6.text.setFont(fonts.general);
	texit.text.setFont(fonts.general);

	// setting sprites textures
	toolsTitle.setTexture(TtoolsTitle.texture);
	toolsMenuBack.setTexture(TtoolsMenuBack.texture);

	// shader setting
	if (!waveEffect.loadFromFile("data/shaders/wave.vert", "data/shaders/blur.frag"))
		exit(3);
}

ToolsMenuRenderer::~ToolsMenuRenderer()
{

}

void ToolsMenuRenderer::setPosition(UInt32 width, UInt32 height)
{
	toolsTitle.setPosition(sf::Vector2f(width / 2 - TtoolsTitle.texture.getSize().x / 2, 50));
	b1.rectform.setPosition(sf::Vector2f(40, 150));
	b2.rectform.setPosition(sf::Vector2f(40, 300));
	b3.rectform.setPosition(sf::Vector2f(width / 2 - 150, 150));
	b4.rectform.setPosition(sf::Vector2f(width / 2 - 150, 300));
	b5.rectform.setPosition(sf::Vector2f(width - 340, 150));
	b6.rectform.setPosition(sf::Vector2f(width - 340, 300));
	bexit.rectform.setPosition(sf::Vector2f(10, height - 90));
	t1.text.setPosition(sf::Vector2f(b1.rectform.getPosition().x + 90, b1.rectform.getPosition().y + 5));
	t2.text.setPosition(sf::Vector2f(b2.rectform.getPosition().x + 80, b2.rectform.getPosition().y + 5));
	t3.text.setPosition(sf::Vector2f(b3.rectform.getPosition().x + 105, b3.rectform.getPosition().y + 5));
	t4.text.setPosition(sf::Vector2f(b4.rectform.getPosition().x + 60, b4.rectform.getPosition().y + 5));
	t5.text.setPosition(sf::Vector2f(b5.rectform.getPosition().x + 105, b5.rectform.getPosition().y + 5));
	t6.text.setPosition(sf::Vector2f(b6.rectform.getPosition().x + 60, b6.rectform.getPosition().y + 5));
	texit.text.setPosition(sf::Vector2f(bexit.rectform.getPosition().x + 45, bexit.rectform.getPosition().y + 5));
}

void ToolsMenuRenderer::setWaveShader(float time)
{
	waveEffect.setUniform("wave_phase", time);
	waveEffect.setUniform("wave_amplitude", sf::Vector2f(0, 0));
	waveEffect.setUniform("blur_radius", time);
}

void ToolsMenuRenderer::render(sf::RenderWindow &window)
{
	window.draw(toolsMenuBack, &waveEffect);
	window.draw(toolsTitle);
	window.draw(b1.rectform);
	window.draw(b2.rectform);
	window.draw(b3.rectform);
	window.draw(b4.rectform);
	window.draw(b5.rectform);
	window.draw(b6.rectform);
	window.draw(bexit.rectform);
	window.draw(t1.text);
	window.draw(t2.text);
	window.draw(t3.text);
	window.draw(t4.text);
	window.draw(t5.text);
	window.draw(t6.text);
	window.draw(texit.text);
}