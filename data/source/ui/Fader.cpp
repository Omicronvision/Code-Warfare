#include "Fader.h"

Fader::Fader()
{
	transitionForm.setSize(sf::Vector2f(1920, 1080));
	transitionForm.setFillColor(sf::Color(0, 0, 0, 0));
}

void Fader::fadeIn(sf::Time time)
{
	if(time.asSeconds() > 0.025f)
	{
		Topacity += 5;
		transitionForm.setFillColor(sf::Color(0, 0, 0, Topacity));
	}
}

void Fader::fadeOut(sf::Time time)
{
	if(time.asSeconds() > 0.025f)
	{
		Topacity -= 5;
		transitionForm.setFillColor(sf::Color(0, 0, 0, Topacity));
	}
}

void Fader::draw(sf::RenderWindow& window)
{
	window.draw(transitionForm);
}

UInt8 Fader::getOpacity()
{
	return Topacity;
}