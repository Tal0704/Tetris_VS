#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Board : sf::Drawable
{
private:
	std::vector<sf::RectangleShape> board;

public:
	

	void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

