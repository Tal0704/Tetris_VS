#pragma once

#include <SFML/Graphics.hpp>
#include <Tetromino.h>
#include <thread>

void fall(Tetromino&, sf::RenderWindow&);

void delay(size_t);
