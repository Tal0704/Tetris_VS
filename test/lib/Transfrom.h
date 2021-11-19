#pragma once
#include <SFML/Graphics.hpp>
#include <thread>

class Transform
{
private:
	sf::RectangleShape *positions;

	sf::Vector2f getMiddle();

public:
	Transform() 
		:positions(nullptr) {}

	enum class Direction { Left = -1, Right = 1};

	void construct(sf::RectangleShape*);

	void move(Transform::Direction );

	void rotate(Transform::Direction);

	void fall();
};