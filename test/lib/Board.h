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
	sf::RenderWindow& m_window;
	sf::Vector2f m_location;
	std::vector<sf::Vector2f> m_maxLocation;
	std::thread m_fallingThread;
	template<size_t size>
	void clearLines(std::vector<size_t>);

public:
	Board(sf::RenderWindow&);
	~Board();
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
