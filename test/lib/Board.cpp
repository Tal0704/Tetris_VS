#include "Board.h"

#define BLOCK_LENGTH 30
#define HALF_BLOCK_SIZE 15

#if defined(_DEBUG)

class Timeing
{
	
};

#endif

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
	:m_size(size), m_location(sf::Vector2f(0.0f, 0.0f)), m_maxLocation(10)
{
	srand((int)time(NULL));
	for (size_t i = 0; i < this->m_maxLocation.size(); i++)
	{
		this->m_maxLocation[i].x = i * BLOCK_LENGTH + HALF_BLOCK_SIZE;
		this->m_maxLocation[i].y = this->m_size.y + HALF_BLOCK_SIZE;
	}
	this->createNewShape();
}

bool Board::isDown()
{
	std::array<sf::Vector2f, 4> newPos;
	for (size_t i = 0; i < newPos.size(); i++)
	{
		newPos[i].x = this->currentShape[i].getPosition().x;
		newPos[i].y = this->currentShape[i].getPosition().y + BLOCK_LENGTH;
	}

	for(const sf::Vector2f& topBlock : this->m_maxLocation)
	{
		for (const sf::Vector2f block : newPos)
		{
			if ((block.x == topBlock.x) && (block.y == topBlock.y))
				return true;
		}
	}

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

void Board::updateTopBlocks()
{
	for (const sf::RectangleShape block : this->m_board)
	{
		for (const sf::RectangleShape above : this->m_board)
		{
			if ((block.getPosition().y - BLOCK_LENGTH != above.getPosition().y) &&
				 block.getPosition().x == above.getPosition().x)
			{
				this->m_maxLocation.push_back(block.getPosition());
			}
		}
	}
}
