#pragma once

#include <SFML/Graphics.hpp>
#include <Tetromino.h>
#include <vector>
#include <array>
#include <thread>
#include <algorithm>

class Board : public sf::Drawable
{
private:
	std::vector<sf::RectangleShape> m_board;
	sf::Vector2u m_size;
	sf::Vector2f m_location;
	std::vector<sf::Vector2f> m_maxLocation;
	template<size_t size>
	void clearLine(std::vector<size_t>);

public:
	Board(sf::Vector2u);
	Tetromino currentShape;

	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void createNewShape();
	void addCurrentShape();
	void updateTopBlocks();
	void rotateShape();
	void moveShape(Tetromino::Direction);
	void instaDrop();
	bool isDown();
	std::vector<size_t> getFullLines();



};
