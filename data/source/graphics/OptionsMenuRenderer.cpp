#include "OptionsMenuRenderer.h"

OptionsMenuRenderer::OptionsMenuRenderer():
tmusic("Enable music", 35, sf::Color::White, sf::Color::Black, 4),
tse("Enable sound effects", 35, sf::Color::White, sf::Color::Black, 4),
tshaders("Enable heavy shaders", 35, sf::Color::White, sf::Color::Black, 4),
tfullscreen("Enable fullscreen", 35, sf::Color::White, sf::Color::Black, 4),
c1("Qwerty controls (WASD)", 35, sf::Color::White, sf::Color::Black, 4),
c2("Azerty controls (ZQSD)", 35, sf::Color::White, sf::Color::Black, 4),
c3("Arrows controls", 35, sf::Color::White, sf::Color::Black, 4),
texit("Go back", 40, sf::Color::White, sf::Color::Black, 4),
b1(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(40, 40)),
b2(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(40, 40)),
b3(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(40, 40)),
b4(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(40, 40)),
cb1(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(40, 40)),
cb2(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(40, 40)),
cb3(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(40, 40)),
bexit(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(150, 80)),
ToptionsTitle("data/graphics/text/options-menu-title.png", false, false),
Tcheck("data/graphics/other/no.png", true, false),
ToptionsMenuBack("data/graphics/other/options-menu-background.png", false, false)
{
	// setting font
	tmusic.text.setFont(fonts.general);
	tse.text.setFont(fonts.general);
	tshaders.text.setFont(fonts.general);
	tfullscreen.text.setFont(fonts.general);
	c1.text.setFont(fonts.general);
	c2.text.setFont(fonts.general);
	c3.text.setFont(fonts.general);
	texit.text.setFont(fonts.general);

	// setting sprites textures
	optionsTitle.setTexture(ToptionsTitle.texture);
	optionsMenuBack.setTexture(ToptionsMenuBack.texture);
	check.setTexture(Tcheck.texture);

	// shader setting
	if (!waveEffect.loadFromFile("data/shaders/wave.vert", "data/shaders/blur.frag"))
		exit(3);
}

OptionsMenuRenderer::~OptionsMenuRenderer()
{

}

void OptionsMenuRenderer::setPosition(UInt32 width, UInt32 height)
{
	optionsTitle.setPosition(sf::Vector2f(width / 2 - ToptionsTitle.texture.getSize().x / 2, 50));
	b1.rectform.setPosition(sf::Vector2f(sf::Vector2f(10, 150)));
	b2.rectform.setPosition(sf::Vector2f(sf::Vector2f(10, 200)));
	b3.rectform.setPosition(sf::Vector2f(sf::Vector2f(10, 250)));
	b4.rectform.setPosition(sf::Vector2f(sf::Vector2f(10, 300)));
	cb1.rectform.setPosition(sf::Vector2f(370, 150));
	cb2.rectform.setPosition(sf::Vector2f(370, 200));
	cb3.rectform.setPosition(sf::Vector2f(370, 250));
	tmusic.text.setPosition(sf::Vector2f(70, 150));
	tse.text.setPosition(sf::Vector2f(70, 200));
	tshaders.text.setPosition(sf::Vector2f(70, 250));
	tfullscreen.text.setPosition(sf::Vector2f(70, 300));
	bexit.rectform.setPosition(sf::Vector2f(10, height - 90));
	texit.text.setPosition(sf::Vector2f(bexit.rectform.getPosition().x + 25, bexit.rectform.getPosition().y + 10));
	c1.text.setPosition(sf::Vector2f(430, 150));
	c2.text.setPosition(sf::Vector2f(430, 200));
	c3.text.setPosition(sf::Vector2f(430, 250));
}

void OptionsMenuRenderer::setWaveShader(float time)
{
	waveEffect.setUniform("wave_phase", time);
	waveEffect.setUniform("wave_amplitude", sf::Vector2f(0, 0));
	waveEffect.setUniform("blur_radius", time);
}

void OptionsMenuRenderer::render(sf::RenderWindow& window, bool music, bool se, bool shaders, bool fullscreen, tristate keys)
{
	window.draw(optionsMenuBack, &waveEffect);
	window.draw(optionsTitle);
	window.draw(b1.rectform);
	window.draw(b2.rectform);
	window.draw(b3.rectform);
	window.draw(b4.rectform);
	window.draw(cb1.rectform);
	window.draw(cb2.rectform);
	window.draw(cb3.rectform);
	window.draw(tmusic.text);
	window.draw(tse.text);
	window.draw(tshaders.text);
	window.draw(tfullscreen.text);
	window.draw(bexit.rectform);
	window.draw(texit.text);
	window.draw(c1.text);
	window.draw(c2.text);
	window.draw(c3.text);

	if (music)
		{check.setPosition(sf::Vector2f(10, 150)); window.draw(check);}
	if (se)
		{check.setPosition(sf::Vector2f(10, 200)); window.draw(check);}
	if (shaders)
		{check.setPosition(sf::Vector2f(10, 250)); window.draw(check);}
	if (fullscreen)
		{check.setPosition(sf::Vector2f(10, 300)); window.draw(check);}
	
	switch(keys)
	{
	case tristate::LOW:
		check.setPosition(sf::Vector2f(370, 150));
		break;
	case tristate::HIGH:
		check.setPosition(sf::Vector2f(370, 200));
		break;
	case tristate::TRISTATE:
		check.setPosition(sf::Vector2f(370, 250));
		break;
	}
	window.draw(check);
}