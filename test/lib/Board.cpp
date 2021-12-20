#include "Board.h"

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (unsigned int i = 0; i < this->m_board.size(); i++)
		target.draw(this->m_board[i]);
	target.draw(this->currentShape);
}

void Board::createNewShape()
{
	int newShape = (int)rand() % 7;
	this->currentShape.setNewShape((Tetromino::Shape)newShape);
}

Board::Board()
	:m_size(sf::Vector2f(355, 635)), m_location(sf::Vector2f(0.0f, 0.0f))
{
	srand((int)time(NULL));
	this->m_maxLocation.fill(sf::Vector2f(0.0f, 0.0f));
	this->createNewShape();
}
