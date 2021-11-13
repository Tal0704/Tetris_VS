#include "Tetromino.h"

#if defined(_DEBUG)
#include <iostream>
#endif // DEBUG

#define MEM_LENGTH_BLOCK 4
#define BLOCK_LENGTH 30
#define HALF_BLOCK_LENGTH 15

#define BACKGROUND_COLOR sf::Color(0xC6, 0xD8, 0xF2)
#define O_COLOR sf::Color(0xFB, 0x00, 0x01)
#define L_COLOR sf::Color(0x03, 0x00, 0xfB)
#define J_COLOR sf::Color(0xBB, 0x02, 0xED)
#define S_COLOR sf::Color(0x63, 0xC4, 0xFF)
#define I_COLOR sf::Color(0xFE, 0x62, 0x00)
#define Z_COLOR sf::Color(0x03, 0xFC, 0x00)
#define T_COLOR sf::Color(0xF4, 0xF7, 0x23)

void Tetromino::init(Tetromino::Kind kind)
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
			this->tetromino[1 * MEM_LENGTH_BLOCK + i].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH + (BLOCK_LENGTH * i)));
			this->tetromino[1 * MEM_LENGTH_BLOCK + i].setFillColor(L_COLOR);
		}
		this->tetromino[1 * MEM_LENGTH_BLOCK + 3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, (2 * BLOCK_LENGTH) + HALF_BLOCK_LENGTH));
		this->tetromino[1 * MEM_LENGTH_BLOCK + 3].setFillColor(L_COLOR);

		break;
	case Tetromino::Kind::J:
		for (int i = 0; i < 3; i++)
		{
			this->tetromino[2 * MEM_LENGTH_BLOCK + i].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH + (BLOCK_LENGTH * i)));
			this->tetromino[2 * MEM_LENGTH_BLOCK + i].setFillColor(J_COLOR);
		}
		this->tetromino[2 * MEM_LENGTH_BLOCK + 3].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, (2 * BLOCK_LENGTH) + HALF_BLOCK_LENGTH));
		this->tetromino[2 * MEM_LENGTH_BLOCK + 3].setFillColor(J_COLOR);

		break;
	case Tetromino::Kind::S:
		this->tetromino[3 * MEM_LENGTH_BLOCK + 0].setPosition(sf::Vector2f(BLOCK_LENGTH * 2 + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));			  // top right
		this->tetromino[3 * MEM_LENGTH_BLOCK + 1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));				  // top left
		this->tetromino[3 * MEM_LENGTH_BLOCK + 2].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		this->tetromino[3 * MEM_LENGTH_BLOCK + 3].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));				  // bottom left
		for (int i = 0; i < 4; i++)
			this->tetromino[5 * MEM_LENGTH_BLOCK + i].setFillColor(S_COLOR);

		break;
	case Tetromino::Kind::I:
		for (int i = 0; i < 4; i++)
		{
			this->tetromino[4 * MEM_LENGTH_BLOCK + i].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, (BLOCK_LENGTH * i) + HALF_BLOCK_LENGTH));
			this->tetromino[4 * MEM_LENGTH_BLOCK + i].setFillColor(I_COLOR);
		}

		break;
	case Tetromino::Kind::Z:
		this->tetromino[5 * MEM_LENGTH_BLOCK + 0].setPosition(sf::Vector2f(HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));									  // top left
		this->tetromino[5 * MEM_LENGTH_BLOCK + 1].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));					  // top right
		this->tetromino[5 * MEM_LENGTH_BLOCK + 2].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH));	  // bottom left
		this->tetromino[5 * MEM_LENGTH_BLOCK + 3].setPosition(sf::Vector2f(BLOCK_LENGTH * 2 + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // bottom right
		for (int i = 0; i < 4; i++)
			this->tetromino[5 * MEM_LENGTH_BLOCK + i].setFillColor(Z_COLOR);

		break;
	case Tetromino::Kind::T:
		for (int i = 0; i < 3; i++)
		{
			this->tetromino[6 * MEM_LENGTH_BLOCK + i].setPosition(sf::Vector2f((BLOCK_LENGTH * i) + HALF_BLOCK_LENGTH, BLOCK_LENGTH + HALF_BLOCK_LENGTH)); // Bottom three
			this->tetromino[6 * MEM_LENGTH_BLOCK + i].setFillColor(T_COLOR);
		}
		this->tetromino[6 * MEM_LENGTH_BLOCK + 3].setPosition(sf::Vector2f(BLOCK_LENGTH + HALF_BLOCK_LENGTH, HALF_BLOCK_LENGTH));
		this->tetromino[6 * MEM_LENGTH_BLOCK + 3].setFillColor(T_COLOR);
		break;
	default:
		break;
	}
}

Tetromino::Tetromino()
	: kind(Tetromino::Kind::O)
{
	transform.construct(this->tetromino);
	for (sf::RectangleShape& tetro : this->tetromino)
	{
		tetro.setSize(sf::Vector2f(BLOCK_LENGTH, BLOCK_LENGTH));
		tetro.setOrigin(sf::Vector2f(tetro.getPosition().x + HALF_BLOCK_LENGTH, tetro.getPosition().y + HALF_BLOCK_LENGTH));
	}
	this->init(Tetromino::Kind::O);
}

Tetromino::Tetromino(Tetromino::Kind kind)
	:kind(kind)
{
	transform.construct(this->tetromino);
	for (sf::RectangleShape& tetro : this->tetromino)
	{
		tetro.setSize(sf::Vector2f(BLOCK_LENGTH, BLOCK_LENGTH));
		tetro.setOrigin(sf::Vector2f(tetro.getPosition().x + HALF_BLOCK_LENGTH, tetro.getPosition().y + HALF_BLOCK_LENGTH));
	}
	this->init(Tetromino::Kind::O);
}

void Tetromino::draw(sf::RenderWindow& window)
{
	window.clear(BACKGROUND_COLOR);

	for (int i = 0; i < 4; i++)
		window.draw(this->tetromino[int(this->kind) * MEM_LENGTH_BLOCK + i]);
	window.display();
#if defined(_DEBUG)
	static int count = 0;
	if (!count)
		for (sf::RectangleShape tetro : this->tetromino)
		{
			std::cout << tetro.getPosition().x << ", " << tetro.getPosition().y << " ";
			std::cout << tetro.getSize().x << ", " << tetro.getSize().y << std::endl;
		}

	count++;
#endif // _DEBUG
}