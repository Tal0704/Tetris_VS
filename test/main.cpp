#include <SFML/Graphics.hpp>
#include <iostream>
#include <Tetromino.h>

// TODO:
// Tetromino.cpp rotate check for right bounderies

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Tetris");
	Tetromino tetro(Tetromino::Kind::I);

	while (window.isOpen())
	{
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                tetro.move(Tetromino::Direction::Left);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                tetro.move(Tetromino::Direction::Right);
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
				tetro.rotate(Tetromino::Direction::Right);
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
				tetro.rotate(Tetromino::Direction::Left);
#if defined(_DEBUG)
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
				tetro.fall();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L)
				tetro.log();
#endif // _DEBUG
		}
		
		tetro.draw(window);
	}

	return 0;
}
