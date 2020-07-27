#include "Chrono.h"

Chrono::Chrono():
elapsedTime(0.0f), state(PAUSED)
{}

void Chrono::start()
{
	if(state != STARTED)
	{
		clock.restart();
		state = STARTED;
	}
}

void Chrono::pause()
{
	if(state != PAUSED)
	{
		state = PAUSED;
		elapsedTime += clock.getElapsedTime().asSeconds();
	}
}

void Chrono::reset()
{
	clock.restart();
	pause();
	elapsedTime = 0.0f;
}

float Chrono::getTimeAsSeconds()
{
	float time;

	if (state == PAUSED)
		time = elapsedTime;
	else
		time = clock.getElapsedTime().asSeconds() + elapsedTime;

	return time;
}

sf::Time Chrono::getTime()
{
	sf::Time time;

	time = clock.getElapsedTime();

	return time;
}