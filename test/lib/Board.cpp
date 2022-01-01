#include "Board.h"

#define BLOCK_LENGTH 30
#define HALF_BLOCK_SIZE 15

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

Board::Board(sf::Vector2u size)
	:m_size(size), m_location(sf::Vector2f(0.0f, 0.0f))
{
	srand((int)time(NULL));
	for (size_t i = 0; i < this->m_maxLocation.size(); i++)
	{
		this->m_maxLocation[i].x = i * BLOCK_LENGTH + HALF_BLOCK_SIZE;
		this->m_maxLocation[i].y = this->m_size.y + BLOCK_LENGTH;
	}
	this->createNewShape();
}

bool Board::isDown()
{
	sf::Vector2f minPos = this->currentShape.getMinPosition();
	for (sf::Vector2f& tetro: this->m_maxLocation)
		if ((tetro.y < minPos.y + (2 * BLOCK_LENGTH) - 1) && tetro.x == minPos.x)
			return true;

	return false;
}

void Board::addCurrentShape()
{
	for (size_t i = 0; i < 4; i++)
	{
		this->m_board.push_back(this->currentShape[i]);
	}

	std::vector<sf::Vector2f> vect(this->m_board.size());
	for (sf::RectangleShape& rect : this->m_board)
	{
		for (size_t i = 0; i < this->m_maxLocation.size(); i++)
		{
			if (rect.getPosition().x == BLOCK_LENGTH * i + HALF_BLOCK_SIZE)
				this->m_maxLocation[i].y = this->m_maxLocation[i].y > rect.getPosition().y ? rect.getPosition().y : this->m_maxLocation[i].y;
		}
	}
}

void Board::rotateShape()
{

}

void Board::moveShape(Tetromino::Direction dir)
{
	std::thread movingThread([&]()
		{
            bool isOutOfBounds = false;
            for (size_t i = 0; i < 4; i++)
            {
                sf::Vector2f temp = this->currentShape[i].getPosition();
                temp.x += BLOCK_LENGTH * (int)dir;
                for (sf::RectangleShape& rect : this->m_board)
                    if (temp.x == rect.getPosition().x && temp.y == rect.getPosition().y)
                        isOutOfBounds = true;
                if (temp.x > this->m_size.x - 1 || temp.x < 0.0f)
                    isOutOfBounds = true;
            }
            if (!isOutOfBounds)
                this->currentShape.move(dir);
		});
	movingThread.join();
}

void Board::instaDrop()
{

}
