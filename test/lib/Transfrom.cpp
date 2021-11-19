#include "Transfrom.h"

#define BLOCK_LENGTH 30.0f

void Transform::construct(sf::RectangleShape* otherShape)
{
	this->positions = otherShape;
}

void Transform::move(Transform::Direction dir)
{
	for (int i = 0; i < 4; i++)
		this->positions[i].move(sf::Vector2f(BLOCK_LENGTH * int(dir), 0));
}

void Transform::rotate(Transform::Direction dir)
{

}

sf::Vector2f Transform::getMiddle()
{
	return sf::Vector2f(0, 0);
}

void Transform::fall()
{
	sf::RectangleShape* position = this->positions;
	static sf::Clock fallingClock;
	fallingClock.restart();
	std::thread fall([&]()
		{
			while (1)
			{
				if (fallingClock.getElapsedTime() == sf::milliseconds(250))
				{
					for (int i = 0; i < 4; i++)
					{
						position[i].move(sf::Vector2f(0, BLOCK_LENGTH));
					}
					fallingClock.restart();
				}
			}
		});
}