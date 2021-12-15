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
	return { 0, 0 };
}