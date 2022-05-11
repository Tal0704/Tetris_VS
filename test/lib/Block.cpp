#include "Block.h"

#if defined(_DEBUG)
#include <debug.h>
#endif

Block::Block(sf::Texture& texture, sf::Vector2f pos)
	: m_sprite(texture)
#if defined(_DEBUG) 
	, m_origin(sf::PrimitiveType::Points, 1) 
#endif
{
	const auto& orig = this->m_sprite.getGlobalBounds();
	this->m_sprite.setOrigin(15, 15);
	this->m_sprite.setPosition(pos);

#if defined(_DEBUG)
	this->m_origin[0].position = this->m_sprite.getOrigin();
	this->m_origin[0].color = sf::Color::Red;
	std::cout << this->m_origin[0].position.x << ", " << this->m_origin[0].position.x << "\n";
#endif
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->m_sprite);
#if defined(_DEBUG)
	target.draw(this->m_origin);
#endif
}

void Block::move(const sf::Vector2f& offset)
{
	const auto& orig = this->m_sprite.getOrigin();
	this->m_sprite.setOrigin(orig + offset);
	this->m_sprite.setPosition(this->m_sprite.getPosition() + offset);
#if defined(_DEBUG)
	this->m_origin[0].position += offset;
	std::cout << "New Positions: " << this->m_sprite.getOrigin() << "\n";
#endif
}

sf::Vector2f Block::getPosition() const
{
	return this->m_sprite.getPosition();
}

#if defined(_DEBUG)
std::ostream& operator<<(std::ostream& stream, const Block& block)
{
	stream << "Position: " << block.getPosition();
	return stream;
}
#endif
