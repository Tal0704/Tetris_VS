#pragma once

#include <math.h>
#include <array>
#include <SFML/Graphics.hpp>

#if defined(_DEBUG)
#include <iostream>
#include <fstream>
#endif // _DEBUG

class Tetromino : public sf::Drawable
{
public:
	enum class Kind { O = 0, L, J, S, I, Z, T };
	enum class Direction { Left = -1, Right = 1};

private:
	Tetromino::Kind kind;
	sf::RectangleShape tetromino[4];
	sf::Vector2f middle;

	void getMiddle();
	void init();
#if defined(_DEBUG)
	sf::VertexArray midPoint;
#endif // _DEBUG

public:

	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void move(Tetromino::Direction);
	void rotate(Tetromino::Direction);
	void fall();
#if defined(_DEBUG)
	void log();
#endif //_DEBUG

	Tetromino();

	Tetromino(Tetromino::Kind);
};