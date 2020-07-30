#include "AnimationSprite.h"

AnimationSprite::AnimationSprite(sf::Time frameTime, bool paused, bool looped, char ID)
	: animation(NULL), frameTime(frameTime), currentFrame(0), isPaused(paused), isLooped(looped), texture(NULL), ID(ID)
{
	frameTime = sf::seconds(0.2f);
}

void AnimationSprite::setAnimation(const Animation& anim)
{
	animation = &anim;
	texture = animation->getSpriteSheet();
	currentFrame = 0;
	setFrame(currentFrame);
}

void AnimationSprite::setFrameTime(sf::Time time)
{
	frameTime = time;
}

void AnimationSprite::playAnimation(const Animation& animation)
{
	if (getAnimation() != &animation)
		setAnimation(animation);
	isPaused = false;
}

void AnimationSprite::pauseAnimation()
{
	isPaused = true;
}

void AnimationSprite::stopAnimation()
{
	isPaused = true;
	currentFrame = 0;
	setFrame(currentFrame);
}

void AnimationSprite::setLooped(bool looped)
{
	isLooped = looped;
}

sf::FloatRect AnimationSprite::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

sf::FloatRect AnimationSprite::getLocalBounds() const
{
	sf::IntRect rect = animation->getFrame(currentFrame);
	float width = static_cast<float>(std::abs(rect.width));
	float height = static_cast<float>(std::abs(rect.height));
	return sf::FloatRect(0.f, 0.f, width, height);
}

bool AnimationSprite::isPause() const
{
	return isPaused;
}

bool AnimationSprite::isLooping() const
{
	return isLooped;
}

const Animation* AnimationSprite::getAnimation() const
{
	return animation;
}

sf::Time AnimationSprite::getFrameTime() const
{
	return frameTime;
}

void AnimationSprite::setFrame(std::size_t newFrame, bool resetTime)
{
	if (animation)
	{
		sf::IntRect rect = animation->getFrame(newFrame);
		vertices[0].position = sf::Vector2f(0.f, 0.f);
		vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
		vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
		vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

		float left = static_cast<float>(rect.left + 0.0001f);
		float right = left + static_cast<float>(rect.width);
		float top = static_cast<float>(rect.top);
		float bottom = top + static_cast<float>(rect.height);

		vertices[0].texCoords = sf::Vector2f(left, top);
		vertices[1].texCoords = sf::Vector2f(left, bottom);
		vertices[2].texCoords = sf::Vector2f(right, bottom);
		vertices[3].texCoords = sf::Vector2f(right, top);
	}
	if (resetTime)
		currentTime = sf::Time::Zero;
}

void AnimationSprite::update(sf::Time deltaTime)
{
	if (!isPaused)
	{
		currentTime += deltaTime;
		if (currentTime.asSeconds() >= sf::seconds(0.1).asSeconds())
		{
			currentTime = sf::microseconds(currentTime.asMicroseconds() % frameTime.asMicroseconds());
			if (currentFrame + 1 < animation->getSize())
				currentFrame++;
			else
			{
				if (!isLooped)
					isPaused = true;
				currentFrame = 0;
			}
			setFrame(currentFrame, false);
		}
	}
}

void AnimationSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (animation && texture)
	{
		states.transform *= getTransform();
		states.texture = texture;
		target.draw(vertices, 4, sf::Quads, states);
	}
}