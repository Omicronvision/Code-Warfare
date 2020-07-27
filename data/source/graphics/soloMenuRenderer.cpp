#include "soloMenuRenderer.h"

SoloMenuRenderer::SoloMenuRenderer() :
texit("Exit", 50, sf::Color::White, sf::Color::Black, 4),
t1("Electrohalls", 40, sf::Color::White, sf::Color::Black, 4),
t2("Vortex", 40, sf::Color::White, sf::Color::Black, 4),
t3("Rectangular path", 40, sf::Color::White, sf::Color::Black, 4),
tE("IDK", 40, sf::Color::White, sf::Color::Black, 4),
bexit(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(150, 80)),
b1(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 200)),
b2(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 200)),
b3(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 200)),
bE(sf::Color::Black, sf::Color::Red, 2, sf::Vector2f(300, 200)),
TsoloPlayerTitle("data/graphics/text/singleplayer-menu-title.png", false, true),
Tdif1("data/graphics/other/dif1.png", true, false),
Tdif2("data/graphics/other/dif2.png", true, false),
Tdif3("data/graphics/other/dif3.png", true, false),
Tcube("data/graphics/icons/greencoin.png", false, false)
{
	// setting font
	texit.text.setFont(fonts.general);
	t1.text.setFont(fonts.general);
	t2.text.setFont(fonts.general);
	t3.text.setFont(fonts.general);
	tE.text.setFont(fonts.general);

	// setting sprites textures
	soloPlayerTitle.setTexture(TsoloPlayerTitle.texture);
	dif1.setTexture(Tdif1.texture);
	dif2.setTexture(Tdif2.texture);
	dif3.setTexture(Tdif3.texture);
}

SoloMenuRenderer::~SoloMenuRenderer()
{

}

void SoloMenuRenderer::setPosition(UInt32 width, UInt32 height)
{
	soloPlayerTitle.setPosition(sf::Vector2f(width / 2 - TsoloPlayerTitle.texture.getSize().x / 2, 50));
	bexit.rectform.setPosition(sf::Vector2f(10, height - 90));
	b1.rectform.setPosition(sf::Vector2f(width / 2 - b1.rectform.getSize().x / 2 - 400, 150));
	b2.rectform.setPosition(sf::Vector2f(width / 2 - b2.rectform.getSize().x / 2, 150));
	b3.rectform.setPosition(sf::Vector2f(width / 2 - b3.rectform.getSize().x / 2 + 400, 150));
	bE.rectform.setPosition(sf::Vector2f(width / 2 - bE.rectform.getSize().x / 2, 400));
	texit.text.setPosition(sf::Vector2f(bexit.rectform.getPosition().x + 38, bexit.rectform.getPosition().y + 5));
	t1.text.setPosition(sf::Vector2f(b1.rectform.getPosition().x + 60, b1.rectform.getPosition().y + 120));
	t2.text.setPosition(sf::Vector2f(b2.rectform.getPosition().x + 100, b2.rectform.getPosition().y + 120));
	t3.text.setPosition(sf::Vector2f(b3.rectform.getPosition().x + 35, b3.rectform.getPosition().y + 120));
	tE.text.setPosition(sf::Vector2f(bE.rectform.getPosition().x + 55, bE.rectform.getPosition().y + 120));
	dif1.setPosition(sf::Vector2f(b1.rectform.getPosition().x + 5, b1.rectform.getPosition().y + 170));
	dif2.setPosition(sf::Vector2f(b2.rectform.getPosition().x + 5, b2.rectform.getPosition().y + 170));
	dif3.setPosition(sf::Vector2f(b3.rectform.getPosition().x + 5, b3.rectform.getPosition().y + 170));
}

void SoloMenuRenderer::render(sf::RenderWindow& window)
{
	window.draw(soloPlayerTitle);
	window.draw(bexit.rectform);
	window.draw(b1.rectform);
	window.draw(b2.rectform);
	window.draw(b3.rectform);
	window.draw(bE.rectform);
	window.draw(texit.text);
	window.draw(t1.text);
	window.draw(t2.text);
	window.draw(t3.text);
	window.draw(tE.text);
	window.draw(dif1);
	window.draw(dif2);
	window.draw(dif3);
}