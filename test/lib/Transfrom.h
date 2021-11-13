#pragma once
#include <SFML/Graphics.hpp>

class Transform
{
private:
	sf::RectangleShape positions[7 * 4];
public:
	void construct(sf::RectangleShape*);
};