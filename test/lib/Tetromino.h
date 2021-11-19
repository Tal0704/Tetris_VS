#pragma once
#include <SFML/Graphics.hpp>
#include <Transfrom.h>

#if defined(_DEBUG)
#include <iostream>
#endif // _DEBUG

class Tetromino
{
public:
	enum class Kind { O = 0, L, J, S, I, Z, T };

private:
	Tetromino::Kind kind;
	sf::RectangleShape tetromino[7 * 4];

	void init();
public:
	void draw(sf::RenderWindow&);

	Transform transform;
	
	Tetromino();
	Tetromino(Tetromino::Kind);

};