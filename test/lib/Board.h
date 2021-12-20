#pragma once

#include <SFML/Graphics.hpp>
#include <Tetromino.h>
#include <vector>
#include <array>

class Board : sf::Drawable
{
private:
	std::vector<sf::RectangleShape> m_board;
	sf::Vector2f m_size;
	sf::Vector2f m_location;
	std::array<sf::Vector2f, 10> m_maxLocation;

public:
	Tetromino currentShape;

	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void createNewShape();
	bool isDown();

	Board();
};

