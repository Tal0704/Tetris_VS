#include "Board.h"

#define BACKGROUND_COLOR sf::Color(0xC6, 0xD8, 0xF2)

Board::Board()
	: currentShape(Tetromino::Kind::O)
{
	this->board.resize(0);
}

void Board::draw(sf::RenderWindow& window)
{
	window.clear(BACKGOUNRD_COLOR); 
	for (sf::RectangleShape block : this->board)
		window.draw(block);
	this->currentShape.draw(window);
	window.display();
}
