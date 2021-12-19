#pragma once

#include <SFML/Graphics.hpp>
#include <Tetromino.h>
#include <vector>
#include <array>

class Board
{
private:
	std::vector<sf::RectangleShape> board;
	Tetromino currentShape;
};

