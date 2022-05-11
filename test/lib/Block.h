#pragma once

#include <SFML/Graphics.hpp>

#if defined(_DEBUG)
#include <iostream>
#endif

class Block : public sf::Drawable
{
private:
	sf::Sprite m_sprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

#if defined(_DEBUG)
	sf::VertexArray m_origin;
#endif

public:
	Block(sf::Texture& texture, sf::Vector2f pos = sf::Vector2f());
	void move(const sf::Vector2f& offset);
	sf::Vector2f getPosition() const;

#if defined(_DEBUG)
	friend std::ostream& operator<<(std::ostream& stream, const Block& block);
#endif
};

