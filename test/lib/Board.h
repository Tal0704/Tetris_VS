#pragma once

#include <SFML/Graphics.hpp>
#include <Tetromino.h>
#include <vector>
#include <array>
#include <thread>

class Board : public sf::Drawable
{
private:
	std::vector<sf::RectangleShape> m_board;
	sf::Vector2u m_size;
	sf::Vector2f m_location;
	std::array<sf::Vector2f, 10> m_maxLocation;

public:
	Board(sf::Vector2u);
	Tetromino currentShape;

	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void createNewShape();
	void addCurrentShape();
	void rotateShape();
	void moveShape(Tetromino::Direction);
	void instaDrop();
	bool isDown();

};
