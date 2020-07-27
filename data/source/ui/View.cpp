#include "View.h"

View::View()
{
	view.reset(sf::FloatRect(0, 0, 1280, 720));

	crosshair.setRadius(5.f);
	crosshair.setOrigin(crosshair.getRadius(), crosshair.getRadius());
	crosshair.setFillColor(sf::Color::White);
	crosshair.setPosition(sf::Vector2f(1250, 1250));
}

void View::resetView(sf::RenderWindow& window, sf::Event &event)
{
	view.reset(sf::FloatRect(0, 0, event.size.width, event.size.height));
	window.setView(view);
}

void View::moveView()
{
	if (crosshair.getPosition().x < variables.minLimit.x)
		crosshair.setPosition(sf::Vector2f(variables.minLimit.x, crosshair.getPosition().y));
	else if (crosshair.getPosition().x > variables.maxLimit.x)
		crosshair.setPosition(sf::Vector2f(variables.maxLimit.x, crosshair.getPosition().y));
	else if (crosshair.getPosition().y < variables.minLimit.y)
		crosshair.setPosition(sf::Vector2f(crosshair.getPosition().x, variables.minLimit.y));
	else if (crosshair.getPosition().y > variables.maxLimit.y)
		crosshair.setPosition(sf::Vector2f(crosshair.getPosition().x, variables.maxLimit.y));

	static float speed = 0;
	static sf::Vector2f previousMove(0, 0);
	static bool isX = false;
	static bool isY = false;

	if((sf::Keyboard::isKeyPressed(variables.moveRight)) || (sf::Keyboard::isKeyPressed(variables.moveLeft))
	|| (sf::Keyboard::isKeyPressed(variables.moveUp)) || (sf::Keyboard::isKeyPressed(variables.moveDown)))
	{
		speed += 0.01f;
		isX = false;
		isY = false;
	} else
	{
		if (!isX)
			previousMove.x = 0;
		if (!isY)
			previousMove.y = 0;
		speed -= 0.01f;
		if (speed < 0)
			speed = 0;
		crosshair.move(previousMove.x * speed, previousMove.y * speed);
	}
	//  check if speed is greater than 1 or small than 0
	if (speed >= 1)
		speed = 1;
	//  check the controls keys
	if (sf::Keyboard::isKeyPressed(variables.moveRight))
	{
		isX = true;
		previousMove.x = 5;
		crosshair.move(speed * 5.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(variables.moveLeft))
	{
		isX = true;
		previousMove.x = -5;
		crosshair.move(speed * -5.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(variables.moveDown))
	{
		isY = true;
		previousMove.y = 5;
		crosshair.move(0, speed * 5.0f);
	}
	if (sf::Keyboard::isKeyPressed(variables.moveUp))
	{
		isY = true;
		previousMove.y = -5;
		crosshair.move(0, speed * -5.0f);
	}
}

void View::zoomView(sf::Vector2i pixel, sf::RenderWindow& window, float zoom)
{
	const sf::Vector2f preCoord(window.mapPixelToCoords(pixel));
	view.zoom(zoom);
	window.setView(view);
	const sf::Vector2f postCoord(window.mapPixelToCoords(pixel));
	const sf::Vector2f offsetCoords(preCoord - postCoord);
	view.move(offsetCoords);
	window.setView(view);
}