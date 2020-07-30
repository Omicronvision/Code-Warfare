#include "FPSClock.h"

FPSClock::FPSClock() :
frame(0), FPS(0),
FPStext("", 20, sf::Color::White, sf::Color::Black, 1)
{
	FPStext.text.setFont(fonts.info);
}

const unsigned int FPSClock::getFPS() const
{
	return FPS;
}

void FPSClock::update()
{
	if (clock.getElapsedTime().asSeconds() >= 1.f)
	{
		FPS = frame;
		frame = 0;
		clock.restart();
	}
	++frame;

	std::ostringstream ss;
	ss << FPS << " FPS";
	FPStext.text.setString(ss.str());
}

void FPSClock::draw(sf::RenderWindow& window)
{
	window.draw(FPStext.text);
}

void FPSClock::setPosition(int x, int y)
{
	FPStext.text.setPosition(x + 5, y + 5);
}