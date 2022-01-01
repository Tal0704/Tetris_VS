#include "Tetromino.h"

#if defined(_DEBUG)
#include <iostream>
#endif // DEBUG

#define MEM_LENGTH_BLOCK 4
#define BLOCK_LENGTH 30.0f
#define HALF_BLOCK_LENGTH 15.0f

#define O_COLOR sf::Color(0xFB, 0x00, 0x01)
#define L_COLOR sf::Color(0x03, 0x00, 0xfB)
#define J_COLOR sf::Color(0xBB, 0x02, 0xED)
#define S_COLOR sf::Color(0x63, 0xC4, 0xFF)
#define I_COLOR sf::Color(0xFE, 0x62, 0x00)
#define Z_COLOR sf::Color(0x03, 0xFC, 0x00)
#define T_COLOR sf::Color(0xF4, 0xF7, 0x23)

void Tetromino::init()
{
	switch (m_shape)
	{
	case Tetromino::Shape::O:
		this->m_tetromino[0].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));								  // top left
		this->m_tetromino[1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));				  // top right
		this->m_tetromino[2].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));				  // bottom left
		this->m_tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		for (int i = 0; i < 4; i++)
			this->m_tetromino[i].setFillColor(O_COLOR);

		break;
	case Tetromino::Shape::L:
		for (int i = 0; i < 3; i++)
		{
			this->m_tetromino[i].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH + (BLOCK_LENGTH * i))); // row 
			this->m_tetromino[i].setFillColor(L_COLOR);
		}
		this->m_tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, (2 * BLOCK_LENGTH) + HALF_BLOCK_LENGTH));
		this->m_tetromino[3].setFillColor(L_COLOR);

		break;
	case Tetromino::Shape::J:
		for (int i = 0; i < 3; i++)
		{
			this->m_tetromino[i].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH + (BLOCK_LENGTH * i)));
			this->m_tetromino[i].setFillColor(J_COLOR);
		}
		this->m_tetromino[3].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, (2 * BLOCK_LENGTH) + HALF_BLOCK_LENGTH));
		this->m_tetromino[3].setFillColor(J_COLOR);

		break;
	case Tetromino::Shape::S:
		this->m_tetromino[0].setPosition(sf::Vector2f(BLOCK_LENGTH * 2 + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));			  // top right
		this->m_tetromino[1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));				  // top left
		this->m_tetromino[2].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		this->m_tetromino[3].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));				  // bottom left
		for (int i = 0; i < 4; i++)
			this->m_tetromino[i].setFillColor(S_COLOR);

		break;
	case Tetromino::Shape::I:
		for (int i = 0; i < 4; i++)
		{
			this->m_tetromino[i].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, (BLOCK_LENGTH * i) + HALF_BLOCK_LENGTH));
			this->m_tetromino[i].setFillColor(I_COLOR);
		}

		break;
	case Tetromino::Shape::Z:
		this->m_tetromino[0].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));									  // top left
		this->m_tetromino[1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));					  // top right
		this->m_tetromino[2].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));	  // bottom left
		this->m_tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH * 2 + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		for (int i = 0; i < 4; i++)
			this->m_tetromino[i].setFillColor(Z_COLOR);

		break;
	case Tetromino::Shape::T:
		for (int i = 0; i < 3; i++)
		{
			this->m_tetromino[i].setPosition(sf::Vector2f((BLOCK_LENGTH * i) + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // Bottom three
			this->m_tetromino[i].setFillColor(T_COLOR);
		}
		this->m_tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));
		this->m_tetromino[3].setFillColor(T_COLOR);
		break;
	default:
		break;
	}
}

Tetromino::Tetromino()
	: m_shape(Tetromino::Shape::O)
{
#if defined(_DEBUG)
	this->midPoint = sf::VertexArray(sf::Points, 1);
#endif //_DEBUG
	for (sf::RectangleShape& tetro : this->m_tetromino)
	{
		tetro.setSize(sf::Vector2f(BLOCK_LENGTH, BLOCK_LENGTH));
		tetro.setOrigin(sf::Vector2f(tetro.getPosition().x + HALF_BLOCK_LENGTH, tetro.getPosition().y + HALF_BLOCK_LENGTH));
		tetro.setOutlineColor(sf::Color::Black);
		tetro.setOutlineThickness(-1);
	}
	this->init();
	this->getMiddle();
#if defined(_DEBUG)
	std::ofstream logs;
	logs.open("logs.txt");
	logs << "Middle of tetromino: " << this->m_middle.x << ", " << m_middle.y << "\n";
	logs.close();
#endif // _DEBUG
}

Tetromino::Tetromino(Tetromino::Shape kind)
	:m_shape(kind)
{
#if defined(_DEBUG)
	this->midPoint = sf::VertexArray(sf::Points, 1);
	this->midPoint[0].color = sf::Color::Black;
#endif //_DEBUG
	for (sf::RectangleShape& tetro : this->m_tetromino)
	{
		tetro.setSize(sf::Vector2f(BLOCK_LENGTH, BLOCK_LENGTH));
		tetro.setOrigin(sf::Vector2f(tetro.getPosition().x + HALF_BLOCK_LENGTH, tetro.getPosition().y + HALF_BLOCK_LENGTH));
		tetro.setOutlineColor(sf::Color::Black);
		tetro.setOutlineThickness(-1);
	}
	this->init();
	this->getMiddle();
#if defined(_DEBUG)
	std::ofstream logs;
	logs.open("logs.txt");
	logs << "Middle of tetromino: " << this->m_middle.x << ", " << m_middle.y << "\n";
	logs.close();
#endif // _DEBUG
}

void Tetromino::draw(sf::RenderTarget& target, sf::RenderStates state) const  
{
	for (int i = 0; i < 4; i++)
		target.draw(this->m_tetromino[i]);
}

void Tetromino::move(Tetromino::Direction dir)
{
	for (sf::RectangleShape& tetro : this->m_tetromino)
		tetro.move(sf::Vector2f(BLOCK_LENGTH * (int)dir, 0.0f));
    this->m_middle += sf::Vector2f(BLOCK_LENGTH * (int)dir, 0.0f);
}

void Tetromino::fall()
{
	for (sf::RectangleShape& tetro : this->m_tetromino)
		tetro.move(sf::Vector2f(0.0f, BLOCK_LENGTH));
    this->m_middle += sf::Vector2f(0.0f, BLOCK_LENGTH);
}

void Tetromino::getMiddle()
{
	sf::Vector2f mid;
	switch (this->m_shape)
	{
	case Tetromino::Shape::O:
		mid.x = this->m_tetromino[0].getPosition().x + HALF_BLOCK_LENGTH;
		mid.y = this->m_tetromino[0].getPosition().y + HALF_BLOCK_LENGTH;
		this->m_middle = mid;

		return;
	case Tetromino::Shape::L:
		this->m_middle = this->m_tetromino[1].getPosition();

		return;
	case Tetromino::Shape::J:
		this->m_middle = this->m_tetromino[1].getPosition();

		return;
	case Tetromino::Shape::S:
		this->m_middle = this->m_tetromino[2].getPosition();

		return;
	case Tetromino::Shape::I:
		mid.x = this->m_tetromino[1].getPosition().x + HALF_BLOCK_LENGTH;
		mid.y = this->m_tetromino[1].getPosition().y + HALF_BLOCK_LENGTH;
		this->m_middle = mid;

		return;
	case Tetromino::Shape::Z:
		this->m_middle = this->m_tetromino[1].getPosition();

		return;
	case Tetromino::Shape::T:
		this->m_middle = this->m_tetromino[1].getPosition();

		return;
	}
}

void Tetromino::rotate(Tetromino::Direction dir)
{
    bool isOutOfBounds = false;
	sf::Vector2f newPos[4];
	for (int i = 0; i < 4; i++)
	{
		// Calculating new positions for each block
		newPos[i].x = -1 * int(dir) * (this->m_tetromino[i].getPosition().y - m_middle.y) + m_middle.x;
		newPos[i].y = int(dir) * this->m_tetromino[i].getPosition().x - this->m_middle.x + this->m_middle.y;
		if (newPos[i].x < 15 || newPos->x > 510)
		{
			isOutOfBounds = true;
			break;
		}
	}
	if(!isOutOfBounds)
		for(int i = 0; i < 4; i++)
            this->m_tetromino[i].setPosition(newPos[i]);
}

#if defined(_DEBUG)
void Tetromino::log()
{
	std::ofstream logs;
	logs.open("logs.txt");
	logs << "Middle of tetromino: " << this->m_middle.x << ", " << m_middle.y << "\n";
	logs << "tetromino[1] = " << this->m_tetromino[1].getPosition().x << ", " << this->m_tetromino[1].getPosition().y << "\n";
	logs << "minPos: " << this->getMinPosition().x << ", " << this->getMinPosition().y;
	logs.close();
}
#endif

void Tetromino::setNewShape(Tetromino::Shape shape)
{
	this->m_shape = shape;
	this->init();
	this->getMiddle();
}

sf::Vector2f Tetromino::getPostion(unsigned int index)
{
	return this->m_tetromino[index].getPosition();
}

sf::Vector2f Tetromino::getMinPosition()
{
	short minIndex = 0;
	for (int i = 1; i < 4; i++)
	{
		if (this->m_tetromino[i].getPosition().y > this->m_tetromino[minIndex].getPosition().y)
			minIndex = i;
	}
	return this->m_tetromino[minIndex].getPosition();

}
