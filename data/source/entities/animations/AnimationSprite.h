#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

class AnimationSprite : public sf::Drawable, public sf::Transformable
{
public:
	AnimationSprite(sf::Time frameTime, bool paused, bool looped, char ID);
	void update(sf::Time deltaTime);
	void setAnimation(const Animation& anim);
	void setFrameTime(sf::Time time);
	void playAnimation(const Animation& animation);
	void pauseAnimation();
	void stopAnimation();
	void setLooped(bool looped);
	const Animation* getAnimation() const;
	sf::FloatRect getGlobalBounds() const;
	sf::FloatRect getLocalBounds() const;
	bool isPause() const;
	bool isLooping() const;
	sf::Time getFrameTime() const;
	void setFrame(std::size_t newFrame, bool resetTime = true);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	const char ID;

private:
	const Animation* animation;
	sf::Time frameTime;
	sf::Time currentTime;
	std::size_t currentFrame;
	bool isPaused;
	bool isLooped;
	const sf::Texture* texture;
	sf::Vertex vertices[4];
};

