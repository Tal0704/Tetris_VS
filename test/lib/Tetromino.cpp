#include "Tetromino.h"

#define BLOCK_LENGTH 30.0f

Tetromino::Tetromino(Tetromino::Shape shape)
{
	for (auto& tetro : this->m_tetro)
	{
		tetro.setOrigin(15.0f, 15.0f);
	}
	std::array<sf::Vector2f, 4> positions;
	switch (shape)
		{
		case Tetromino::Shape::O:
			this->m_texture.loadFromFile("media/tetros/blue.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			break;
		case Tetromino::Shape::L:
			this->m_texture.loadFromFile("media/tetros/green.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			break;
		case Tetromino::Shape::J:
			this->m_texture.loadFromFile("media/tetros/orange.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			break;
		case Tetromino::Shape::S:
			this->m_texture.loadFromFile("media/tetros/purple.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			break;
		case Tetromino::Shape::I:
			this->m_texture.loadFromFile("media/tetros/red.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			break;
		case Tetromino::Shape::Z:
			this->m_texture.loadFromFile("media/tetros/teal.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			break;
		case Tetromino::Shape::T:
			this->m_texture.loadFromFile("media/tetros/yello.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			break;
		default:
			break;
		}

		for (size_t i = 0; i < this->m_tetro.size(); i++)
		{
			auto& tetro = this->m_tetro[i];
			tetro.setTexture(this->m_texture);
			tetro.setPosition(positions[i]);
		}
}

void Tetromino::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& tetro:  this->m_tetro)
		target.draw(tetro, states);
}
