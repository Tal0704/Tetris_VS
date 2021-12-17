#include "Tetromino.h"

#if defined(_DEBUG)
#include <iostream>
#endif // DEBUG

#define MEM_LENGTH_BLOCK 4
#define BLOCK_LENGTH 30.0f
#define HALF_BLOCK_LENGTH 15.0f

#define BACKGROUND_COLOR sf::Color(0xC6, 0xD8, 0xF2)
#define O_COLOR sf::Color(0xFB, 0x00, 0x01)
#define L_COLOR sf::Color(0x03, 0x00, 0xfB)
#define J_COLOR sf::Color(0xBB, 0x02, 0xED)
#define S_COLOR sf::Color(0x63, 0xC4, 0xFF)
#define I_COLOR sf::Color(0xFE, 0x62, 0x00)
#define Z_COLOR sf::Color(0x03, 0xFC, 0x00)
#define T_COLOR sf::Color(0xF4, 0xF7, 0x23)

void Tetromino::init()
{
	switch (kind)
	{
	case Tetromino::Kind::O:
		this->tetromino[0].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));								  // top left
		this->tetromino[1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));				  // top right
		this->tetromino[2].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));				  // bottom left
		this->tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		for (int i = 0; i < 4; i++)
			this->tetromino[i].setFillColor(O_COLOR);

		break;
	case Tetromino::Kind::L:
		for (int i = 0; i < 3; i++)
		{
			this->tetromino[i].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH + (BLOCK_LENGTH * i))); // row 
			this->tetromino[i].setFillColor(L_COLOR);
		}
		this->tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, (2 * BLOCK_LENGTH) + HALF_BLOCK_LENGTH));
		this->tetromino[3].setFillColor(L_COLOR);

		break;
	case Tetromino::Kind::J:
		for (int i = 0; i < 3; i++)
		{
			this->tetromino[i].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH + (BLOCK_LENGTH * i)));
			this->tetromino[i].setFillColor(J_COLOR);
		}
		this->tetromino[3].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, (2 * BLOCK_LENGTH) + HALF_BLOCK_LENGTH));
		this->tetromino[3].setFillColor(J_COLOR);

		break;
	case Tetromino::Kind::S:
		this->tetromino[0].setPosition(sf::Vector2f(BLOCK_LENGTH * 2 + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));			  // top right
		this->tetromino[1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));				  // top left
		this->tetromino[2].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		this->tetromino[3].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));				  // bottom left
		for (int i = 0; i < 4; i++)
			this->tetromino[i].setFillColor(S_COLOR);

		break;
	case Tetromino::Kind::I:
		for (int i = 0; i < 4; i++)
		{
			this->tetromino[i].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, (BLOCK_LENGTH * i) + HALF_BLOCK_LENGTH));
			this->tetromino[i].setFillColor(I_COLOR);
		}

		break;
	case Tetromino::Kind::Z:
		this->tetromino[0].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));									  // top left
		this->tetromino[1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));					  // top right
		this->tetromino[2].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));	  // bottom left
		this->tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH * 2 + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		for (int i = 0; i < 4; i++)
			this->tetromino[i].setFillColor(Z_COLOR);

		break;
	case Tetromino::Kind::T:
		for (int i = 0; i < 3; i++)
		{
			this->tetromino[i].setPosition(sf::Vector2f((BLOCK_LENGTH * i) + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // Bottom three
			this->tetromino[i].setFillColor(T_COLOR);
		}
		this->tetromino[3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));
		this->tetromino[3].setFillColor(T_COLOR);
		break;
	default:
		break;
	}
}

Tetromino::Tetromino()
	: kind(Tetromino::Kind::O)
{
	this->midPoint = sf::VertexArray(sf::Points, 1);
	for (sf::RectangleShape& tetro : this->tetromino)
	{
		tetro.setSize(sf::Vector2f(BLOCK_LENGTH, BLOCK_LENGTH));
		tetro.setOrigin(sf::Vector2f(tetro.getPosition().x + HALF_BLOCK_LENGTH, tetro.getPosition().y + HALF_BLOCK_LENGTH));
	}
	this->init();
	this->getMiddle();
#if defined(_DEBUG)
	std::ofstream logs;
	logs.open("logs.txt");
	logs << "Middle of tetromino: " << this->middle.x << ", " << middle.y << "\n";
	logs.close();
#endif // _DEBUG
}

Tetromino::Tetromino(Tetromino::Kind kind)
	:kind(kind)
{
	this->midPoint = sf::VertexArray(sf::Points, 1);
	this->midPoint[0].color = sf::Color::Black;
	for (sf::RectangleShape& tetro : this->tetromino)
	{
		tetro.setSize(sf::Vector2f(BLOCK_LENGTH, BLOCK_LENGTH));
		tetro.setOrigin(sf::Vector2f(tetro.getPosition().x + HALF_BLOCK_LENGTH, tetro.getPosition().y + HALF_BLOCK_LENGTH));
	}
	this->init();
	this->getMiddle();
#if defined(_DEBUG)
	std::ofstream logs;
	logs.open("logs.txt");
	logs << "Middle of tetromino: " << this->middle.x << ", " << middle.y << "\n";
	logs.close();
#endif // _DEBUG
}

void Tetromino::draw(sf::RenderWindow& window)
{
	window.clear(BACKGROUND_COLOR);

	for (sf::RectangleShape& tetro : this->tetromino)
		window.draw(tetro);
#if defined(_DEBUG)
	this->midPoint[0].position = this->middle;
	window.draw(this->midPoint);
#endif //_DEBUG
	window.display();
}

void Tetromino::move(Tetromino::Direction dir)
{
	for (sf::RectangleShape& tetro : this->tetromino)
		tetro.move(sf::Vector2f(BLOCK_LENGTH * (int)dir, 0.0f));
    this->middle += sf::Vector2f(BLOCK_LENGTH * (int)dir, 0.0f);
	
}

void Tetromino::fall()
{
	for (sf::RectangleShape& tetro : this->tetromino)
		tetro.move(sf::Vector2f(0.0f, BLOCK_LENGTH));
    this->middle += sf::Vector2f(0.0f, BLOCK_LENGTH);
}

void Tetromino::getMiddle()
{
	sf::Vector2f mid;
	switch (this->kind)
	{
	case Tetromino::Kind::O:
		mid.x = this->tetromino[0].getPosition().x + HALF_BLOCK_LENGTH;
		mid.y = this->tetromino[0].getPosition().y + HALF_BLOCK_LENGTH;
		this->middle = mid;

		return;
	case Tetromino::Kind::L:
		this->middle = this->tetromino[1].getPosition();

		return;
	case Tetromino::Kind::J:
		this->middle = this->tetromino[1].getPosition();

		return;
	case Tetromino::Kind::S:
		this->middle = this->tetromino[2].getPosition();

		return;
	case Tetromino::Kind::I:
		mid.x = this->tetromino[1].getPosition().x + HALF_BLOCK_LENGTH;
		mid.y = this->tetromino[1].getPosition().y + HALF_BLOCK_LENGTH;
		this->middle = mid;

		return;
	case Tetromino::Kind::Z:
		this->middle = this->tetromino[2].getPosition();

		return;
	case Tetromino::Kind::T:
		this->middle = this->tetromino[1].getPosition();

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
		newPos[i].x = -1 * int(dir) * (this->tetromino[i].getPosition().y - middle.y) + middle.x;
		newPos[i].y = int(dir) * this->tetromino[i].getPosition().x - this->middle.x + this->middle.y;
		if (newPos[i].x < 15 || newPos->x > 510)
		{
			isOutOfBounds = true;
			break;
		}
	}
	if(!isOutOfBounds)
		for(int i = 0; i < 4; i++)
            this->tetromino[i].setPosition(newPos[i]);
}

#if defined(_DEBUG)
void Tetromino::log()
{
	std::ofstream logs;
	logs.open("logs.txt");
	logs << "Middle of tetromino: " << this->middle.x << ", " << middle.y << "\n";
	logs << "tetromino[1] = " << this->tetromino[1].getPosition().x << ", " << this->tetromino[1].getPosition().y << "\n";
	logs.close();
}
#endif
