#pragma once

#include <SFML/Graphics.hpp>

class Chrono
{
public:
	Chrono();
	void start();
	void pause();
	void reset();
	float getTimeAsSeconds();
	sf::Time getTime();

private:
	enum State {PAUSED, STARTED};
	State state;
	sf::Clock clock;
	float elapsedTime;
};