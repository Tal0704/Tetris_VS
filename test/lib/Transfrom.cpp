#include "Transfrom.h"

void Transform::construct(sf::RectangleShape* other)
{
	memcpy(this->positions, other, 7 * 4);
}